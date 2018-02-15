// FileName:  Mask.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 08:53
// Description:   

namespace mhxy.NetEase.Maps {

    /// <summary>
    ///     Mask 对象
    /// </summary>
    public class Mask {

        /// <summary>
        ///     遮罩数据
        /// </summary>
        public Mask(int startX, int startY, int width, int height, int size) {
            StartX = startX;
            StartY = startY;
            Width = width;
            Height = height;
            Size = size;
            Data = new byte[size];
        }

        /// <summary>
        ///     X
        /// </summary>
        public int StartX { get; private set; }

        /// <summary>
        ///     Y
        /// </summary>
        public int StartY { get; private set; }

        /// <summary>
        ///     宽度
        /// </summary>
        public int Width { get; private set; }

        /// <summary>
        ///     高度
        /// </summary>
        public int Height { get; private set; }

        /// <summary>
        ///     对齐宽度
        /// </summary>
        public int AlignWidth { get; set; }

        /// <summary>
        ///     大小
        /// </summary>
        public int Size { get; private set; }

        /// <summary>
        ///     原始数据
        /// </summary>
        public byte[] Data { get; set; }

        /// <summary>
        ///     处理后的数据
        /// </summary>
        public byte[] DecodedData { get; set; }

    }

}