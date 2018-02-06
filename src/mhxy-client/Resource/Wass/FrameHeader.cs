// FileName:  FrameHeader.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180206 16:33
// Description:   

namespace mhxy.Resource.Wass {

    /// <summary>
    /// 帧头部
    /// </summary>
    public class FrameHeader {

        /// <summary>
        /// 图片的关键位X
        /// </summary>
        public int KeyX { get; set; }

        /// <summary>
        /// 图片的关键位Y
        /// </summary>
        public int KeyY { get; set; }

        /// <summary>
        /// 图片的宽度，单位像素
        /// </summary>
        public int Width { get; set; }

        /// <summary>
        ///  图片的高度，单位像素
        /// </summary>
        public int Height { get; set; }

    }

}