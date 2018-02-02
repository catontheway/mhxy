// FileName:  Map.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 08:53
// Description:   

#region

using System;
using System.IO;

#endregion

namespace mhxy.Resource.Maps {

    /// <summary>
    ///     地图对象
    /// </summary>
    public class Map : ResourceBase {

        /// <summary>
        ///     使用文件名构造Map对象
        /// </summary>
        /// <param name="fileName">地图文件名</param>
        public Map(string fileName) {
            if (!File.Exists(fileName)) {
                throw new FileNotFoundException(fileName);
            }

            _fileName = fileName;
            Logger.Info($"Create Map:{fileName}");
        }

        /// <summary>
        ///     加载资源
        /// </summary>
        public override void Load() {
            if (_loaded) {
                return;
            }

            Logger.Info($"Begin Load Map:{_fileName}");
            try {
                var buffer4 = new byte[4];
                using (var fs = new FileStream(_fileName, FileMode.Open)) {
                    //1.Read Header
                    //1.1.Read Width Height
                    fs.Read(buffer4, 0, 4);
                    _flag = BitConverter.ToString(buffer4);
                    fs.Read(buffer4, 0, 4);
                    _width = BitConverter.ToInt32(buffer4, 0);
                    fs.Read(buffer4, 0, 4);
                    _height = BitConverter.ToInt32(buffer4, 0);
                    _unitColumns = _width / 320;
                    _unitRows = _height / 240;
                    _unitSize = _unitColumns * _unitRows;
                    _unitOffsets = new int[_unitSize];
                    _units = new Unit[_unitSize];
                    Logger.Info($"Flag(302E314D):{_flag},Width:{_width}" +
                                $",Height:{_height},Unit Columns:{_unitColumns}" +
                                $",Unit Rows:{_unitRows},Unit Size:{_unitSize}");
                    //1.2.Read Unit Indexes
                    for (var i = 0; i < _unitSize; i++) {
                        fs.Read(buffer4, 0, 4);
                        _unitOffsets[i] = BitConverter.ToInt32(buffer4, 0);
                        Logger.Debug($"Unit:{i},Offset:{_unitOffsets[i]}");
                    }

                    //1.3.Read Mask Header
                    fs.Read(buffer4, 0, 4);
                    _maskFlag = BitConverter.ToString(buffer4);
                    fs.Read(buffer4, 0, 4);
                    _maskSize = BitConverter.ToInt32(buffer4, 0);
                    _maskOffsets = new int[_maskSize];
                    _masks = new Mask[_maskSize];
                    Logger.Info($"Mask Head Flag(70030000):{_maskFlag},Mask Size:{_maskSize}");
                    for (var i = 0; i < _maskSize; i++) {
                        fs.Read(buffer4, 0, 4);
                        _maskOffsets[i] = BitConverter.ToInt32(buffer4, 0);
                        Logger.Debug($"Mask:{i},Offset:{_maskOffsets[i]}");
                    }

                    fs.Seek(0, SeekOrigin.Begin);
                    //2.Read Mask
                    for (int i = 0; i < _maskSize; i++) {
                        _masks[i] = ReadMask(fs, i, _maskOffsets[i]);
                    }

                    //3.Read Unit
                    for (int i = 0; i < _unitSize; i++) {
                        _units[i] = ReadUnit(fs, i, _unitOffsets[i]);
                    }
                }
            } catch (Exception e) {
                Logger.Error($"Error In Load Map:{_fileName}", e);
            }

            Logger.Info($"End Load Map:{_fileName}");
            _loaded = true;
        }

        /// <summary>
        ///     从文件中读取Mask数据
        /// </summary>
        /// <param name="fs"></param>
        /// <param name="index"></param>
        /// <param name="offSet"></param>
        /// <returns></returns>
        private Mask ReadMask(FileStream fs, int index, int offSet) {
            var buffer4 = new byte[4];
            fs.Seek(offSet, SeekOrigin.Begin);
            fs.Read(buffer4, 0, 4);
            int startX = BitConverter.ToInt32(buffer4, 0);
            fs.Read(buffer4, 0, 4);
            int startY = BitConverter.ToInt32(buffer4, 0);
            fs.Read(buffer4, 0, 4);
            int width = BitConverter.ToInt32(buffer4, 0);
            fs.Read(buffer4, 0, 4);
            int height = BitConverter.ToInt32(buffer4, 0);
            fs.Read(buffer4, 0, 4);
            int size = BitConverter.ToInt32(buffer4, 0);
            var mask = new Mask(startX, startY, width, height, size);
            Logger.Debug(
                $"Read Mask({index}:{offSet}):StartX:{startX},StartY:{startY},Width:{width},Height:{height},Size:{size}");
            for (var i = 0; i < size; i++) {
                fs.Read(buffer4, 0, 4);
                mask.Data[i] = BitConverter.ToInt32(buffer4, 0);
            }

            return mask;
        }

        /// <summary>
        ///     从文件中读取unit数据
        /// </summary>
        /// <param name="fs"></param>
        /// <param name="index"></param>
        /// <param name="offSet"></param>
        /// <returns></returns>
        private Unit ReadUnit(FileStream fs, int index, int offSet) {
            fs.Seek(offSet, SeekOrigin.Begin);
            var buffer4 = new byte[4];
            fs.Read(buffer4, 0, 4);
            uint realOffset = BitConverter.ToUInt32(buffer4, 0);
            fs.Seek(realOffset * 4, SeekOrigin.Current);
            UnitData jpeg = ReadUnitData(fs);
            UnitData cell = ReadUnitData(fs);
            UnitData brig = ReadUnitData(fs);
            var unit = new Unit(realOffset, jpeg, cell, brig);
            Logger.Debug($"Read Unit({index}:{offSet}):RealOffset:{realOffset}");
            Logger.Debug($"UnitData(jpeg):Flag(47-45-50-4A):{jpeg.Flag},Size:{jpeg.Size}"); //也可能是 32-47-50-4A,JPG
            Logger.Debug($"UnitData(cell):Flag(4C-4C-45-43):{cell.Flag},Size:{cell.Size}");
            Logger.Debug($"UnitData(brig):Flag(47-49-52-42):{brig.Flag},Size:{brig.Size}");
            return unit;
        }

        /// <summary>
        /// </summary>
        /// <param name="fs"></param>
        /// <returns></returns>
        private UnitData ReadUnitData(FileStream fs) {
            var buffer4 = new byte[4];
            fs.Read(buffer4, 0, 4);
            var flag = BitConverter.ToString(buffer4);
            fs.Read(buffer4, 0, 4);
            int size = BitConverter.ToInt32(buffer4, 0);
            var unitData = new UnitData(flag, size);
            fs.Read(unitData.Data, 0, unitData.Data.Length);
            return unitData;
        }

        /// <summary>
        ///     卸载资源
        /// </summary>
        public override void Unload() {
            Dispose();
        }

        #region Fields And Properties

        #region Map Data

        private readonly string _fileName;

        private bool _loaded;

        /// <summary>
        ///     地图标识
        /// </summary>
        private string _flag;

        /// <summary>
        ///     宽度
        /// </summary>
        private int _width;

        /// <summary>
        ///     高度
        /// </summary>
        private int _height;

        /// <summary>
        ///     unit列数量
        /// </summary>
        private int _unitColumns;

        /// <summary>
        ///     unit行数量
        /// </summary>
        private int _unitRows;

        /// <summary>
        ///     unit数量
        /// </summary>
        private int _unitSize;

        /// <summary>
        ///     unit偏移值
        /// </summary>
        private int[] _unitOffsets;

        /// <summary>
        ///     mask 标识
        /// </summary>
        private string _maskFlag;

        /// <summary>
        ///     mask 大小
        /// </summary>
        private int _maskSize;

        /// <summary>
        ///     mask 偏移值
        /// </summary>
        private int[] _maskOffsets;

        ///// <summary>
        /////     unit是否加载
        ///// </summary>
        //private bool[] _unitLoaded;

        /// <summary>
        ///     地图单元
        /// </summary>
        private Unit[] _units;

        /// <summary>
        ///     Mask 信息
        /// </summary>
        private Mask[] _masks;

        #endregion

        #endregion

    }

}

/************************************************************************
Map File Format
======================= Begin Map Head =======================
4字节     标识,值为:0x302E314D
4字节     地图的宽度
4字节     地图的高度
4*n字节   地图单元的索引,n=(地图的宽度/640*2) * (地图高度/480*2)
4字节     Mask 标识
4字节     Mask 大小
4*m字节   Mask 索引，m大小为：Mask 大小
======================= End Map Head =========================
======================= Begin Mask Data ======================
======================= Begin Mask ===========================
4字节     StartX
4字节     StartY
4字节     Width
4字节     Height
4字节     数据大小
4*s字节   s大小为：Size 大小
======================= End Mask =============================
======================= Begin Mask ===========================
...
======================= End Mask =============================
======================= End Mask Data ========================
======================= Begin Unit Data ======================
======================= Begin Unit ===========================
4字节 地图单元引索的开始位置。
n*4字节 n为上面的值，n为0时不存在。

4字节 GEPJ (JPEG)
4字节 大小
n字节 数据

4字节 LLEC (CELL)
4字节 大小
n字节 数据

4字节 BRIG (GIRB)
4字节 大小
n字节 数据

4字节 结束单元(0x00 0x00 0x00 0x00)。
======================= End Unit =============================
======================= Begin Unit ===========================
...
======================= End Unit =============================
======================= End Unit Data ========================
************************************************************************/