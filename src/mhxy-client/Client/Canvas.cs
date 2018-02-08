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
            Lowest = new Bitmap(width, height, PixelFormat.Format32bppArgb);
            Lower = new Bitmap(width, height, PixelFormat.Format32bppArgb);
            Normal = new Bitmap(width, height, PixelFormat.Format32bppArgb);
            Higher = new Bitmap(width, height, PixelFormat.Format32bppArgb);
            Highest = new Bitmap(width, height, PixelFormat.Format32bppArgb);
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
        ///     实际显示的世界区域
        /// </summary>
        public Point WorldPoint { get; set; }

        /// <summary>
        /// </summary>
        //public Bitmap Bitmap { get; }
        /// <summary>
        ///     最底层(例如,场景图)
        /// </summary>
        public Bitmap Lowest { get; }

        /// <summary>
        ///     稍底层(例如,Player)
        /// </summary>
        public Bitmap Lower { get; }

        /// <summary>
        ///     正常层(例如,系统界面，聊天窗口)
        /// </summary>
        public Bitmap Normal { get; }

        /// <summary>
        ///     稍高层(例如,属性窗口等)
        /// </summary>
        public Bitmap Higher { get; }

        /// <summary>
        ///     最高层(消息)
        /// </summary>
        public Bitmap Highest { get; }

    }

}