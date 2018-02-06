// FileName:  WasManager.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 08:53
// Description:   

#region

using System;
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

        private string _wdfPath;

        public bool TryGetWas(string fileId, int wasId, out Was wds) {
            throw new NotImplementedException();
        }

    }

}