// FileName:  SpHeader.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180206 16:32
// Description:   

using System;

namespace mhxy.Resource.Wass {

    /// <summary>
    /// Was精灵文件头
    /// </summary>
    public class SpHeader {

        /// <summary>
        ///精灵文件标志 SP 0x5053
        /// </summary>
        public string Flag { get; set; }

        /// <summary>
        /// 文件头的长度 默认为 12 不包括Length字段
        /// </summary>
        public UInt16 Length { get; set; }

        /// <summary>
        ///  精灵图片的组数，即方向数
        /// </summary>
        public UInt16 Group { get; set; }

        /// <summary>
        /// 每组的图片数，即帧数
        /// </summary>
        public UInt16 Frame { get; set; }

        /// <summary>
        /// 精灵动画的宽度，单位像素
        /// </summary>
        public UInt16 Width { get; set; }

        /// <summary>
        /// 精灵动画的高度，单位像素
        /// </summary>
        public UInt16 Height { get; set; }

        /// <summary>
        /// 精灵动画的关键位X
        /// </summary>
        public UInt16 KeyX { get; set; }

        /// <summary>
        ///  精灵动画的关键位Y
        /// </summary>
        public UInt16 KeyY { get; set; }
    }

}