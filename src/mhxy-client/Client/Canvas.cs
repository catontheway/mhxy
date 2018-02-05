// FileName:  Canvas.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180205 09:31
// Description:   

using System.Drawing;
using System.Drawing.Imaging;

namespace mhxy.Client {

    /// <summary>
    /// 画布
    /// </summary>
    public class Canvas {

        /// <summary>
        /// 
        /// </summary>
        /// <param name="width"></param>
        /// <param name="height"></param>
        public Canvas(int width, int height) {
            Width = width;
            Height = height;
            //Data = new byte[width * height * 3];
            Bitmap = new Bitmap(width, height, PixelFormat.Format32bppArgb);
        }

        /// <summary>
        /// 画布宽度
        /// </summary>
        public int Width { get; }

        /// <summary>
        /// 画布高度
        /// </summary>
        public int Height { get; }

        /// <summary>
        /// 显示的世界左上角坐标X
        /// </summary>
        public int WorldPointX { get; set; }


        /// <summary>
        /// 显示的世界左上角坐标Y
        /// </summary>
        public int WorldPointY { get; set; }

        ///// <summary>
        ///// 
        ///// </summary>
        //public byte[] Data { get; }

        /// <summary>
        /// 
        /// </summary>
        public Bitmap Bitmap { get; }

    }

}