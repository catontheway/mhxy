// FileName:  Mask.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 08:53
// Description:   

namespace mhxy.Resource.Maps {

    /// <summary>
    ///     Mask 对象
    /// </summary>
    public class Mask {

        /// <summary>
        /// </summary>
        public Mask(int startX, int startY, int width, int height, int size) {
            StartX = startX;
            StartY = startY;
            Width = width;
            Height = height;
            Size = size;
            Data = new int[size];
        }

        /// <summary>
        ///     X
        /// </summary>
        public int StartX { get; set; }

        /// <summary>
        ///     Y
        /// </summary>
        public int StartY { get; set; }

        /// <summary>
        ///     宽度
        /// </summary>
        public int Width { get; set; }

        /// <summary>
        ///     高度
        /// </summary>
        public int Height { get; set; }

        /// <summary>
        ///     大小
        /// </summary>
        public int Size { get; set; }

        /// <summary>
        ///     数据
        /// </summary>
        public int[] Data { get; set; }

    }

}