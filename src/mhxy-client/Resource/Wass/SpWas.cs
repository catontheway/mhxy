// FileName:  SpWas.cs
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

//using System.Drawing;
//using ImageProcessor;
//using ImageProcessor.Imaging.Formats;
//using StbSharp;

namespace mhxy.Resource.Wass {

    /// <summary>
    ///     Was资源对象
    /// </summary>
    public class SpWas : ResourceBase {

        /// <summary>
        /// </summary>
        /// <param name="fileName"></param>
        /// <param name="wasInfo"></param>
        public SpWas(string fileName, WasInfo wasInfo) {
            if (!File.Exists(fileName)) {
                throw new FileNotFoundException(fileName);
            }

            _fileName = fileName;
            _wasInfo = wasInfo;
        }

        private readonly string _fileName;
        private readonly WasInfo _wasInfo;

        private readonly uint[] _palette32 = new uint[256];
        private readonly ushort[] _palette16 = new ushort[256];

        private bool _loaded;
        private uint[,] _frameIndexes;
        private SpFrame[,] _frames;

        /// <summary>
        /// </summary>
        public SpHeader SpHeader { get; private set; }

        /// <summary>
        ///     加载Was文件
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
                        throw new InvalidDataException($"Error In Load Was : Not A SP File {flag}");
                    }

                    //读取SP Was Header
                    SpHeader = new SpHeader {Flag = flag};
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
                    Logger.Info(
                        $"SpWas({_fileName}) Header:Flag:{SpHeader.Flag},Length:{SpHeader.Length},Group:{SpHeader.Group},Frame:{SpHeader.Frame}" +
                        $",Width:{SpHeader.Width},Height:{SpHeader.Height},KeyX:{SpHeader.KeyX},KeyY:{SpHeader.KeyY}");
                    if (SpHeader.Length != 12) {
                        fs.Seek(SpHeader.Length - 12, SeekOrigin.Current);
                    }

                    //读取调色板数据
                    for (int i = 0; i < 256; i++) {
                        fs.Read(buffer2, 0, 2);
                        _palette16[i] = BitConverter.ToUInt16(buffer2, 0);
                        _palette32[i] = Rgb16ToRgb32(_palette16[i], 0xFF);
                    }

                    //读取Frame索引
                    _frameIndexes = new uint[SpHeader.Group, SpHeader.Frame];
                    for (int group = 0; group < SpHeader.Group; group++) {
                        for (int frame = 0; frame < SpHeader.Frame; frame++) {
                            fs.Read(buffer4, 0, 4);
                            _frameIndexes[group, frame] = BitConverter.ToUInt32(buffer4, 0);
                        }
                    }

                    //读取Frame数据
                    _frames = new SpFrame[SpHeader.Group, SpHeader.Frame];
                    int pixels = SpHeader.Width * SpHeader.Height;
                    int[] frameLine = new int[SpHeader.Height * 4]; // 分配行引索列表的空间
                    int frameHeadOffset = SpHeader.Length + 4; // 头部的实际长度 SpHeader.Length + Length占的长度
                    for (int group = 0; group < SpHeader.Group; group++) {
                        for (int frame = 0; frame < SpHeader.Frame; frame++) {
                            uint frameIndex = _frameIndexes[group, frame];
                            fs.Seek(_wasInfo.Offset + frameHeadOffset + frameIndex, SeekOrigin.Begin);
                            var spFrame = new SpFrame {
                                BitmapHeight = SpHeader.Height,
                                BitmapWidth = SpHeader.Width
                                //Data = new byte[pixels * 4]
                            };
                            // 读取Frame Header
                            fs.Read(buffer4, 0, 4);
                            spFrame.KeyX = BitConverter.ToInt32(buffer4, 0);
                            fs.Read(buffer4, 0, 4);
                            spFrame.KeyY = BitConverter.ToInt32(buffer4, 0);
                            fs.Read(buffer4, 0, 4);
                            spFrame.Width = BitConverter.ToInt32(buffer4, 0);
                            fs.Read(buffer4, 0, 4);
                            spFrame.Height = BitConverter.ToInt32(buffer4, 0);
                            for (int h = 0; h < spFrame.Height; h++) {
                                fs.Read(buffer4, 0, 4);
                                frameLine[h] = BitConverter.ToInt32(buffer4, 0);
                            }

                            uint[] buffer = new uint[pixels];
                            //开始读取
                            for (int j = 0; j < spFrame.Height; j++) {
                                int startIndex = SpHeader.Width * j;
                                int lineDataLen;
                                // 得到行数据的大小
                                if (j < spFrame.Height - 1) {
                                    lineDataLen = frameLine[j + 1] - frameLine[j];
                                } else {
                                    if (group == SpHeader.Group - 1 && frame == SpHeader.Frame - 1) {
                                        lineDataLen = _wasInfo.Size - ((int) frameIndex + frameLine[j]);
                                    } else {
                                        int frame2 = frame == SpHeader.Frame - 1 ? 0 : frame + 1;
                                        int group2 = frame2 == 0 ? group + 1 : group;
                                        lineDataLen = (int) _frameIndexes[group2, frame2] -
                                                      ((int) frameIndex + frameLine[j]);
                                    }
                                }

                                var lineData = new byte[SpHeader.Width * 4]; // 分配行数据的空间
                                fs.Seek(_wasInfo.Offset + frameIndex + frameHeadOffset + frameLine[j],
                                    SeekOrigin.Begin);
                                fs.Read(lineData, 0, lineDataLen);
                                int pixelOffset = SpHeader.KeyX - spFrame.KeyX;
                                int pixelLen = SpHeader.Width;
                                startIndex += pixelOffset;
                                startIndex += (SpHeader.KeyY - spFrame.KeyY) * SpHeader.Width;
                                DataHandler(lineData, buffer, startIndex, pixelOffset, pixelLen);
                            }

                            //for (int i = 0; i < buffer.Length; i++) {
                            //    var bytes = BitConverter.GetBytes(buffer[i]);
                            //    spFrame.Data[i * 4 + 0] = bytes[0];
                            //    spFrame.Data[i * 4 + 1] = bytes[1];
                            //    spFrame.Data[i * 4 + 2] = bytes[2];
                            //    spFrame.Data[i * 4 + 3] = bytes[3];
                            //}
                            spFrame.Bitmap = new Bitmap(spFrame.BitmapWidth, spFrame.BitmapHeight);
                            using (FastBitmap fastBitmap = new FastBitmap(spFrame.Bitmap)) {
                                fastBitmap.Lock();
                                for (int w = 0; w < spFrame.BitmapWidth; w++) {
                                    for (int h = 0; h < spFrame.BitmapHeight; h++) {
                                        fastBitmap.SetPixel(w, h, buffer[h * spFrame.BitmapWidth + w]);
                                    }
                                }

                                fastBitmap.Unlock();
                            }

                            //using (var stream = new MemoryStream()) {
                            //    var writer = new ImageWriter();
                            //    var image = new StbSharp.Image { Comp = 4, Data = spFrame.Data, Height = spFrame.BitmapHeight, Width = spFrame.BitmapWidth };
                            //    writer.WriteBmp(image, stream);
                            //    var bitmapData = stream.ToArray();
                            //    spFrame.Bitmap = new Bitmap(spFrame.BitmapWidth, spFrame.BitmapHeight);
                            //    using (var imageFactory = new ImageFactory()) {
                            //        if (imageFactory.Load(bitmapData).Format(new BitmapFormat()).Image is Bitmap bitmap) {
                            //            spFrame.Bitmap = new Bitmap(bitmap);
                            //        }
                            //    }
                            //}
                            _frames[group, frame] = spFrame;
                        }
                    }
                }

                _loaded = true;
            } catch (Exception e) {
                Logger.Error($"Error In Load Was : {_fileName}", e);
                throw;
            }

            Logger.Info($"End Load Was : {_fileName}");
        }

        private void DataHandler(byte[] pData, uint[] dest, int destIndex, int pixelOffset, int pixelLen) {
            int pixels = pixelOffset;
            int pixelLength = pixelLen;
            int pDataIndex = 0;
            while (pData[pDataIndex] != 0) // {00000000} 表示像素行结束，如有剩余像素用透明色代替
            {
                byte repeat; // 重复次数
                var style = (byte) ((pData[pDataIndex] & 0xc0) >> 6);
                switch (style) {
                    case 0: // {00******}
                        ushort alphaPixel;
                        byte level; // Alpha层数
                        if ((pData[pDataIndex] & 0x20) != 0) // {001*****} 表示带有Alpha通道的单个像素
                        {
                            // {001 +5bit Alpha}+{1Byte Index}, 表示带有Alpha通道的单个像素。
                            // {001 +0~31层Alpha通道}+{1~255个调色板引索}
                            level = (byte) (pData[pDataIndex] & 0x1f); // 0x1f=(11111) 获得Alpha通道的值
                            pDataIndex++; // 下一个字节
                            if (pixels < pixelLength) {
                                alphaPixel = Alpha565(_palette16[pData[pDataIndex]], 0, level); // 混合
                                dest[destIndex++] = Rgb16ToRgb32(alphaPixel, (byte) (level * 8));
                                pixels++;
                                pDataIndex++;
                            }
                        } else // {000*****} 表示重复n次带有Alpha通道的像素
                        {
                            // {000 +5bit Times}+{1Byte Alpha}+{1Byte Index}, 表示重复n次带有Alpha通道的像素。
                            // {000 +重复1~31次}+{0~255层Alpha通道}+{1~255个调色板引索}
                            // 注: 这里的{00000000} 保留给像素行结束使用，所以只可以重复1~31次。
                            repeat = (byte) (pData[pDataIndex] & 0x1f); // 获得重复的次数
                            pDataIndex++;
                            level = pData[pDataIndex]; // 获得Alpha通道值
                            pDataIndex++;
                            for (int i = 1; i <= repeat; i++) {
                                if (pixels < pixelLength) {
                                    alphaPixel = Alpha565(_palette16[pData[pDataIndex]], 0, level); // 混合
                                    dest[destIndex++] = Rgb16ToRgb32(alphaPixel, (byte) (level * 8));
                                    pixels++;
                                }
                            }

                            pDataIndex++;
                        }

                        break;
                    case 1: // {01******} 表示不带Alpha通道不重复的n个像素组成的数据段
                        // {01  +6bit Times}+{nByte Datas},表示不带Alpha通道不重复的n个像素组成的数据段。
                        // {01  +1~63个长度}+{n个字节的数据},{01000000}保留。
                        repeat = (byte) (pData[pDataIndex] & 0x3f); // 获得数据组中的长度
                        pDataIndex++;
                        for (int i = 1; i <= repeat; i++) {
                            if (pixels < pixelLength) {
                                dest[destIndex++] = _palette32[pData[pDataIndex]];
                                pixels++;
                                pDataIndex++;
                            }
                        }

                        break;
                    case 2: // {10******} 表示重复n次像素
                        // {10  +6bit Times}+{1Byte Index}, 表示重复n次像素。
                        // {10  +重复1~63次}+{0~255个调色板引索},{10000000}保留。
                        repeat = (byte) (pData[pDataIndex] & 0x3f); // 获得重复的次数
                        pDataIndex++;
                        for (int i = 1; i <= repeat; i++) {
                            if (pixels < pixelLength) {
                                dest[destIndex++] = _palette32[pData[pDataIndex]];
                                pixels++;
                            }
                        }

                        pDataIndex++;
                        break;
                    case 3: // {11******} 表示跳过n个像素，跳过的像素用透明色代替
                        // {11  +6bit Times}, 表示跳过n个像素，跳过的像素用透明色代替。
                        // {11  +跳过1~63个像素},{11000000}保留。
                        repeat = (byte) (pData[pDataIndex] & 0x3f); // 获得重复次数
                        for (int i = 1; i <= repeat; i++) {
                            if (pixels < pixelLength) {
                                destIndex++;
                                pixels++;
                            }
                        }

                        pDataIndex++;
                        break;
                }
            }

            if (pData[pDataIndex] == 0) {
                var repeat = (byte) (pixelLength - pixels);
                for (int i = 0; i < repeat; i++) {
                    if (pixels < pixelLength) {
                        destIndex++;
                        pixels++;
                    }
                }
            }
        }

        /// <summary>
        ///     获取一帧数据
        /// </summary>
        /// <param name="group"></param>
        /// <param name="frame"></param>
        /// <returns></returns>
        public SpFrame GetFrame(int group, int frame) {
            if (!_loaded) {
                throw new InvalidDataException("not loaed");
            }

            if (group > SpHeader.Group || frame > SpHeader.Frame) {
                throw new IndexOutOfRangeException($"Group:{SpHeader.Group},Frame:{SpHeader.Frame}");
            }

            return _frames[group, frame];
        }

        public override void Unload() {
        }

        public override void Save() {
            if (!_loaded) {
                return;
            }

            Logger.Info($"Begin Save SPWas : {_wasInfo.Uid}@{_fileName}");
            for (int group = 0; group < SpHeader.Group; group++) {
                for (int frame = 0; frame < SpHeader.Frame; frame++) {
                    var spFrame = _frames[group, frame];
                    var fileName = $"{_fileName}_{_wasInfo.Uid}_{group}.{frame}.bmp";
                    try {
                        using (var imageFactory = new ImageFactory()) {
                            imageFactory.Load(spFrame.Bitmap).Format(new BitmapFormat()).Save(fileName);
                        }
                    } catch (Exception e) {
                        Logger.Error($"Save Map : {fileName}", e);
                    }
                }
            }

            Logger.Info($"End Save SPWas : {_fileName}");
        }

        private static uint Rgb16ToRgb32(ushort color, byte alpha) {
            uint r = (uint) (color >> 11) & 0x1f;
            uint g = (uint) (color >> 5) & 0x3f;
            uint b = (uint) color & 0x1f;
            uint a2 = alpha;
            uint r2 = (r << 3) | (r >> 2);
            uint g2 = (g << 2) | (g >> 4);
            uint b2 = (b << 3) | (b >> 2);
            return (a2 << 24) | (r2 << 16) | (g2 << 8) | b2;
            //return a2 << 24 | (b2 << 16) | (g2 << 8) | r2;
        }

        private static ushort Alpha565(ushort src, ushort des, ushort alpha) {
            // 混合后的颜色=( ( A-B ) * Alpha ) >> 5 + B
            // 混合后的颜色 = ( A * Alpha + B * ( 32-Alpha ) ) / 32

            var rSrc = (ushort) (src & 0xF800);
            var gSrc = (ushort) (src & 0x07E0);
            var bSrc = (ushort) (src & 0x001F);

            rSrc = (ushort) (rSrc >> 11);
            gSrc = (ushort) (gSrc >> 5);

            var rDes = (ushort) (des & 0xF800);
            var gDes = (ushort) (des & 0x07E0);
            var bDes = (ushort) (des & 0x001F);

            rDes = (ushort) (rDes >> 11);
            gDes = (ushort) (gDes >> 5);

            var rRes = (ushort) (((rSrc - rDes) * alpha) >> (5 + rDes));
            var gRes = (ushort) (((gSrc - gDes) * alpha) >> (5 + gDes));
            var bRes = (ushort) (((bSrc - bDes) * alpha) >> (5 + bDes));

            rRes = (ushort) (rRes << 11);
            gRes = (ushort) (gRes << 5);
            var result = (ushort) (rRes | gRes | bRes);
            return result;
        }

    }

}