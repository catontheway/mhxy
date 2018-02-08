using System.Drawing;

namespace mhxy.Resource.Wass {

    /// <summary>
    /// 帧数据
    /// </summary>
    public class SpFrame {

        /// <summary>
        /// 透明色
        /// </summary>
        public Color ColorA0 = Color.FromArgb(0, 0, 0, 0);

        /// <summary>
        /// 图片的关键位X
        /// </summary>
        public int KeyX { get; set; }

        /// <summary>
        /// 图片的关键位Y
        /// </summary>
        public int KeyY { get; set; }

        /// <summary>
        /// 原始图片的宽度，单位像素
        /// </summary>
        public int Width { get; set; }

        /// <summary>
        /// 原始图片的高度，单位像素
        /// </summary>
        public int Height { get; set; }

        /// <summary>
        /// 图片的宽度，单位像素
        /// </summary>
        public int BitmapWidth { get; set; }

        /// <summary>
        ///  图片的高度，单位像素
        /// </summary>
        public int BitmapHeight { get; set; }

        ///// <summary>
        ///// 原始数据
        ///// </summary>
        //public byte[] Data { get; set; }

        /// <summary>
        /// 
        /// </summary>
        public Bitmap Bitmap { get; set; }
    }
}
