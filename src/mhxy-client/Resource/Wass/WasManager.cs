// FileName:  WasManager.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 08:53
// Description:   

#region

using System;
using System.Collections.Concurrent;
using System.IO;
using mhxy.Common;

#endregion

namespace mhxy.Resource.Wass {

    /// <summary>
    ///     Was 资源管理器
    /// </summary>
    public class WasManager : ServiceBase, IWasManager {

        public WasManager(string wdfPath) {
            _wdfPath = wdfPath;
            Logger.Debug($"Create MapManager : {wdfPath}");
        }

        private readonly string _wdfPath;
        private readonly ConcurrentDictionary<string, Wdf> _wdfs = new ConcurrentDictionary<string, Wdf>();
        private readonly ConcurrentDictionary<int, SpWas> _wass = new ConcurrentDictionary<int, SpWas>();

        /// <summary>
        ///     获取Was
        /// </summary>
        /// <param name="wdfFileId"></param>
        /// <param name="wasId"></param>
        /// <param name="was"></param>
        /// <returns></returns>
        public bool TryGetSpWas(string wdfFileId, int wasId, out SpWas was) {
            try {
                if (!_wass.TryGetValue(wasId, out was)) {
                    if (!_wdfs.TryGetValue(wdfFileId, out Wdf wdf)) {
                        wdf = new Wdf(wdfFileId, Path.Combine(_wdfPath, wdfFileId));
                        wdf.Load();
                        _wdfs[wdfFileId] = wdf;
                    }

                    if (!wdf.TryGetSpWas(wasId, out was)) {
                        Logger.Warn($"Not Fount Was: {wasId}@{wdfFileId}");
                        return false;
                    }

                    _wass[wasId] = was;
                }
            } catch (Exception e) {
                Logger.Error($"Error In Get Was: {wasId}@{wdfFileId}", e);
                was = null;
            }

            return true;
        }

    }

}