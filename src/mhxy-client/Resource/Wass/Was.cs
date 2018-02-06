// FileName:  Was.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 08:53
// Description:   

using System;
using System.IO;

namespace mhxy.Resource.Wass {

    /// <summary>
    ///     Was资源对象
    /// </summary>
    public class Was : ResourceBase {

        /// <summary>
        /// 
        /// </summary>
        /// <param name="fileName"></param>
        /// <param name="wasInfo"></param>
        public Was(string fileName, WasInfo wasInfo) {
            if (!File.Exists(fileName)) {
                throw new FileNotFoundException(fileName);
            }
            _fileName = fileName;
            _wasInfo = wasInfo;
        }

        private bool _loaded;
        private readonly string _fileName;
        private readonly WasInfo _wasInfo;

        /// <summary>
        /// 
        /// </summary>
        public SpHeader SpHeader { get; private set; }

        /// <summary>
        /// 加载Was文件
        /// </summary>
        public override void Load() {
            if (_loaded) {
                return;
            }
            Logger.Info($"Begin Load Was : {_fileName}");
            var buffer4 = new byte[4];
            var buffer2 = new byte[2];
            try {
                using (var fs = new FileStream(_fileName, FileMode.Open)) {
                    fs.Seek(_wasInfo.Offset, SeekOrigin.Begin);
                    fs.Read(buffer2, 0, 2);
                    var flag = BitConverter.ToString(buffer2, 0);
                    if (!string.Equals(flag, "53-50")) {
                        Logger.Error($"Error In Load Was : Not A SP File {flag}");
                        return;
                    }
                    SpHeader = new SpHeader { Flag = flag };
                    fs.Read(buffer2, 0, 2);
                    SpHeader.Length = BitConverter.ToUInt16(buffer2, 0);
                    fs.Read(buffer2, 0, 2);
                    SpHeader.Group = BitConverter.ToUInt16(buffer2, 0);
                    fs.Read(buffer2, 0, 2);
                    SpHeader.Frame = BitConverter.ToUInt16(buffer2, 0);
                    fs.Read(buffer2, 0, 2);
                    SpHeader.Width = BitConverter.ToUInt16(buffer2, 0);
                    fs.Read(buffer2, 0, 2);
                    SpHeader.Height = BitConverter.ToUInt16(buffer2, 0);
                    fs.Read(buffer2, 0, 2);
                    SpHeader.KeyX = BitConverter.ToUInt16(buffer2, 0);
                    fs.Read(buffer2, 0, 2);
                    SpHeader.KeyY = BitConverter.ToUInt16(buffer2, 0);
                }
                _loaded = true;
            } catch (Exception e) {
                Logger.Error($"Error In Load Was : {_fileName}", e);
                throw;
            }
            Logger.Info($"End Load Was : {_fileName}");
        }
    }

}