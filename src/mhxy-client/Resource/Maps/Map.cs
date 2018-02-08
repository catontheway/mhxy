// FileName:  Map.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 08:53
// Description:   

#region

using System;
using System.Drawing;
using System.IO;
using ImageProcessor;
using ImageProcessor.Imaging.Formats;
using mhxy.Utils;

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
        /// </summary>
        /// <param name="rect"></param>
        /// <returns></returns>
        public Image GetParialImage(Rectangle rect) {
            using (var imageFactory = new ImageFactory()) {
                return imageFactory.Load(_bitmap).Format(new JpegFormat()).Format(new BitmapFormat()).Crop(rect).Image
                    .Clone() as Image;
            }
        }

        /// <summary>
        ///     加载资源
        /// </summary>
        public override void Load() {
            if (_loaded) {
                return;
            }

            Logger.Info($"Begin Load Map : {_fileName}");
            try {
                var buffer4 = new byte[4];
                using (var fs = new FileStream(_fileName, FileMode.Open)) {
                    //1.Read Header
                    //1.1.Read Width Height
                    fs.Read(buffer4, 0, 4);
                    _flag = BitConverter.ToString(buffer4);
                    fs.Read(buffer4, 0, 4);
                    _width = BitConverter.ToInt32(buffer4, 0);
                    MaxX = _width - Global.Width;
                    fs.Read(buffer4, 0, 4);
                    _height = BitConverter.ToInt32(buffer4, 0);
                    MaxY = _height - Global.Height;
                    _unitColumns = (int) Math.Ceiling((double) Width / Global.WidthPerMapCell);
                    _unitRows = (int) Math.Ceiling((double) Height / Global.HeightPerMapCell);
                    _unitSize = _unitColumns * _unitRows;
                    _unitOffsets = new int[_unitSize];
                    _units = new Unit[_unitSize];
                    Logger.Info($"Flag(302E314D):{_flag},Width:{Width}" +
                                $",Height:{Height},Unit Columns:{_unitColumns}" +
                                $",Unit Rows:{_unitRows},Unit Size:{_unitSize}");
                    //1.2.Read Unit Indexes
                    for (var i = 0; i < _unitSize; i++) {
                        fs.Read(buffer4, 0, 4);
                        _unitOffsets[i] = BitConverter.ToInt32(buffer4, 0);
                        //Logger.Debug($"Unit:{i},Offset:{_unitOffsets[i]}");
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
                        //Logger.Debug($"Mask:{i},Offset:{_maskOffsets[i]}");
                    }

                    fs.Seek(0, SeekOrigin.Begin);
                    //2.Read Mask
                    for (int i = 0; i < _maskSize; i++) {
                        _masks[i] = ReadMask(fs, _maskOffsets[i]);
                    }

                    //3.Read Unit
                    for (int i = 0; i < _unitSize; i++) {
                        _units[i] = ReadUnit(fs, _unitOffsets[i]);
                    }
                    //4.Process Mask

                    //5.Create BitMap
                    _bitmap = new Bitmap(Width, Height);
                    using (ImageFactory factory = new ImageFactory()) {
                        for (var rowIndex = 0; rowIndex < _unitRows; rowIndex++) {
                            for (var colIndex = 0; colIndex < _unitColumns; colIndex++) {
                                var index = colIndex + _unitColumns * rowIndex;
                                var unit = _units[index];
                                if (!unit.Decoded) {
                                    continue;
                                }
                                if (factory.Load(unit.RealImage)
                                    .Image is Bitmap unitBitmap) {
                                    FastBitmap.CopyRegion(unitBitmap, _bitmap,
                                        new Rectangle(0, 0, unitBitmap.Width, unitBitmap.Height),
                                        new Rectangle(colIndex * 320, rowIndex * 240, unitBitmap.Width
                                            , unitBitmap.Height));
                                }
                            }
                        }
                    }
                }
                _loaded = true;
            } catch (Exception e) {
                Logger.Error($"Error In Load Map : {_fileName}", e);
                throw;
            }

            Logger.Info($"End Load Map : {_fileName}");
        }

        /// <summary>
        ///     将map文件另存为jpg图像
        /// </summary>
        public override void Save() {
            if (!_loaded) {
                return;
            }
            Logger.Info($"Begin Save Map : {_fileName}");
            var fileName = _fileName + ".jpg";
            try {
                using (var imageFactory = new ImageFactory()) {
                    imageFactory.Load(_bitmap).Format(new JpegFormat()).Save(fileName);
                }
            } catch (Exception e) {
                Logger.Error($"Save Map : {fileName}", e);
            }

            Logger.Info($"End Save Map : {_fileName}");
        }

        /// <summary>
        ///     从文件中读取Mask数据
        /// </summary>
        /// <param name="fs"></param>
        /// <param name="offSet"></param>
        /// <returns></returns>
        private Mask ReadMask(FileStream fs, int offSet) {
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
            //Logger.Debug($"Read Mask({index}:{offSet}):StartX:{startX},StartY:{startY},Width:{width},Height:{height},Size:{size}");
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
        /// <param name="offSet"></param>
        /// <returns></returns>
        private Unit ReadUnit(FileStream fs, int offSet) {
            fs.Seek(offSet, SeekOrigin.Begin);
            var buffer4 = new byte[4];
            fs.Read(buffer4, 0, 4);
            uint realOffset = BitConverter.ToUInt32(buffer4, 0);
            fs.Seek(realOffset * 4, SeekOrigin.Current);
            UnitData img = ReadUnitData(fs);
            UnitData cell = ReadUnitData(fs);
            UnitData brig = ReadUnitData(fs);
            var unit = new Unit(realOffset, img, cell, brig);
            if (string.Equals(img.Flag, "47-45-50-4A")) {
                // JPEG
                unit.Decoded = DecodeJpeg(img.Data, out byte[] realImage);
                unit.RealImage = realImage;
            } else if (string.Equals(img.Flag, "32-47-50-4A")) {
                // JPG
                unit.Decoded = true;
                unit.RealImage = img.Data;
            }
            //Logger.Debug($"Read Unit({index}:{offSet}):RealOffset:{realOffset}");
            //Logger.Debug($"UnitData(jpeg):Flag(47-45-50-4A):{jpeg.Flag},Size:{jpeg.Size}"); //也可能是 32-47-50-4A,JPG
            //Logger.Debug($"UnitData(cell):Flag(4C-4C-45-43):{cell.Flag},Size:{cell.Size}");
            //Logger.Debug($"UnitData(brig):Flag(47-49-52-42):{brig.Flag},Size:{brig.Size}");
            return unit;
        }

        private bool DecodeJpeg(byte[] origin, out byte[] result) {
            int inSize = origin.Length;
            int incrementSize = 0;
            int originIndex = 0;
            int resultIndex = 0;
            int processedCount = 0;
            var tempResult = new byte[inSize * 2];
            byte[] byte2 = new byte[2];
            result = null;
            try {
                // 当已读取数据的长度小于总长度时继续
                while (processedCount < inSize && origin[originIndex++] == 0xFF) {
                    tempResult[resultIndex++] = 0xFF;
                    processedCount++;
                    ushort tempTimes; // 临时变量，表示循环的次数
                    switch (origin[originIndex]) {
                        case 0xD8:
                            tempResult[resultIndex++] = 0xD8;
                            originIndex++;
                            processedCount++;
                            break;
                        case 0xA0:
                            originIndex++;
                            resultIndex--;
                            processedCount++;
                            break;
                        case 0xC0:
                            tempResult[resultIndex++] = 0xC0;
                            originIndex++;
                            processedCount++;
                            byte2[1] = origin[originIndex];
                            byte2[0] = origin[originIndex + 1];
                            tempTimes = BitConverter.ToUInt16(byte2, 0);
                            for (int i = 0; i < tempTimes; i++) {
                                tempResult[resultIndex++] = origin[originIndex++];
                                processedCount++;
                            }

                            break;
                        case 0xC4:
                            tempResult[resultIndex++] = 0xC4;
                            originIndex++;
                            processedCount++;
                            byte2[1] = origin[originIndex];
                            byte2[0] = origin[originIndex + 1];
                            tempTimes = BitConverter.ToUInt16(byte2, 0);
                            for (int i = 0; i < tempTimes; i++) {
                                tempResult[resultIndex++] = origin[originIndex++];
                                processedCount++;
                            }

                            break;
                        case 0xDB:
                            tempResult[resultIndex++] = 0xDB;
                            originIndex++;
                            processedCount++;
                            byte2[1] = origin[originIndex];
                            byte2[0] = origin[originIndex + 1];
                            tempTimes = BitConverter.ToUInt16(byte2, 0);
                            for (int i = 0; i < tempTimes; i++) {
                                tempResult[resultIndex++] = origin[originIndex++];
                                processedCount++;
                            }

                            break;
                        case 0xDA:
                            tempResult[resultIndex++] = 0xDA;
                            tempResult[resultIndex++] = 0x00;
                            tempResult[resultIndex++] = 0x0C;
                            originIndex++;
                            processedCount++;
                            byte2[1] = origin[originIndex];
                            byte2[0] = origin[originIndex + 1];
                            tempTimes = BitConverter.ToUInt16(byte2, 0);
                            originIndex++;
                            processedCount++;
                            originIndex++;
                            for (int i = 2; i < tempTimes; i++) {
                                tempResult[resultIndex++] = origin[originIndex++];
                                processedCount++;
                            }

                            tempResult[resultIndex++] = 0x00;
                            tempResult[resultIndex++] = 0x3F;
                            tempResult[resultIndex++] = 0x00;
                            // 循环处理0xFFDA到0xFFD9之间所有的0xFF替换为0xFF00
                            for (; processedCount < inSize - 2;) {
                                if (origin[originIndex] == 0xFF) {
                                    tempResult[resultIndex++] = 0xFF;
                                    tempResult[resultIndex++] = 0x00;
                                    originIndex++;
                                    processedCount++;
                                    incrementSize++;
                                } else {
                                    tempResult[resultIndex++] = origin[originIndex++];
                                    processedCount++;
                                }
                            }

                            // 直接在这里写上了0xFFD9结束Jpeg图片.
                            incrementSize--; // 这里多了一个字节，所以减去。
                            resultIndex--;
                            tempResult[resultIndex--] = 0xD9;
                            break;
                        case 0xD9:
                            // 算法问题，这里不会被执行，但结果一样。
                            tempResult[resultIndex++] = 0xD9;
                            processedCount++;
                            break;
                    }
                }

                result = new byte[incrementSize + inSize];
                Array.Copy(tempResult, 0, result, 0, incrementSize + inSize);
            } catch {
                return false;
            }

            return true;
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

        /// <summary>
        ///     地图图像
        /// </summary>
        public Bitmap Bitmap => _bitmap;

        /// <summary>
        ///     宽度
        /// </summary>
        public int Width => _width;

        /// <summary>
        ///     高度
        /// </summary>
        public int Height => _height;

        /// <summary>
        ///     为了显示
        /// </summary>
        public int MaxX { get; private set; }

        /// <summary>
        ///     为了显示
        /// </summary>
        public int MaxY { get; private set; }


        /// <summary>
        ///     地图图像
        /// </summary>
        private Bitmap _bitmap;

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