// FileName:  Wdf.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180206 13:56
// Description:   

#region

using System;
using System.Collections.Generic;
using System.IO;

#endregion

namespace mhxy.Resource.Wass {

    /// <summary>
    ///     Wdf 文件
    /// </summary>
    public class Wdf : ResourceBase {

        /// <summary>
        /// </summary>
        /// <param name="id"></param>
        /// <param name="fileName"></param>
        public Wdf(string id, string fileName) {
            if (!File.Exists(fileName)) {
                throw new FileNotFoundException(fileName);
            }
            FileId = id;
            FileName = fileName;
        }

        private bool _loaded;
        private string _flag;
        private int _wasFileCount;
        private int _offset;

        /// <summary>
        ///     WDF 文件名
        /// </summary>
        public string FileName { get; }

        /// <summary>
        ///     编号
        /// </summary>
        public string FileId { get; }


        private readonly Dictionary<int, WasInfo> _wasInfos = new Dictionary<int, WasInfo>();

        /// <summary>
        ///     加载wdf 资源
        /// </summary>
        public override void Load() {
            if (_loaded) {
                return;
            }
            Logger.Info($"Begin Load Wdf : {FileName}");
            var buffer4 = new byte[4];
            try {
                using (var fs = new FileStream(FileName, FileMode.Open)) {
                    fs.Read(buffer4, 0, 4);
                    _flag = BitConverter.ToString(buffer4);
                    fs.Read(buffer4, 0, 4);
                    _wasFileCount = BitConverter.ToInt32(buffer4, 0);
                    fs.Read(buffer4, 0, 4);
                    _offset = BitConverter.ToInt32(buffer4, 0);
                    Logger.Info($"Flag(50-46-44-57):{_flag},WasFileCount:{_wasFileCount},Offset:{_offset}");
                    if (string.Equals(_flag, "50-46-44-57")) {
                        fs.Seek(_offset, SeekOrigin.Begin);
                        // 读取文件列表
                        for (int i = 0; i < _wasFileCount; i++) {
                            fs.Read(buffer4, 0, 4);
                            int uid = BitConverter.ToInt32(buffer4, 0);
                            fs.Read(buffer4, 0, 4);
                            int size = BitConverter.ToInt32(buffer4, 0);
                            fs.Read(buffer4, 0, 4);
                            int offset = BitConverter.ToInt32(buffer4, 0);
                            fs.Read(buffer4, 0, 4);
                            int space = BitConverter.ToInt32(buffer4, 0);
                            var wasInfo = new WasInfo(uid, size, offset, space);
                            Logger.Debug($"Was({uid}):Size:{size},Offset:{offset},Space:{space}");
                            _wasInfos[uid] = wasInfo;
                        }
                    } else {
                        _wasFileCount = 0;
                    }
                }
                _loaded = true;
            } catch (Exception e) {
                Logger.Error($"Error In Load Wdf : {FileName}", e);
                throw;
            }
            Logger.Info($"End Load Wdf : {FileName}");
        }

        /// <summary>
        /// 获取文件中的Was
        /// </summary>
        /// <param name="wasId"></param>
        /// <param name="was"></param>
        /// <returns></returns>
        public bool TryGetWas(int wasId, out Was was) {
            was = null;
            if (_wasInfos.TryGetValue(wasId, out WasInfo wasInfo)) {
                was = new Was(FileName, wasInfo);
                was.Load();
            }
            return false;
        }
    }

}