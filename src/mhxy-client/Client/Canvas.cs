// FileName:  Canvas.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180205 13:58
// Description:   

#region

using System.Drawing;
using System.Drawing.Imaging;

#endregion

namespace mhxy.Client {

    /// <summary>
    ///     画布
    /// </summary>
    public class Canvas {

        /// <summary>
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
        ///     画布宽度
        /// </summary>
        public int Width { get; }

        /// <summary>
        ///     画布高度
        /// </summary>
        public int Height { get; }

        /// <summary>
        ///     实际显示的世界区域(以左上角的世界坐标表示)
        /// </summary>
        public Point WorldPoint { get; set; }

        /// <summary>
        /// </summary>
        public Bitmap Bitmap { get; }

    }

}