// FileName:  DrawArgs.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180208 17:42
// Description:   

#region

using System.Drawing;
using mhxy.Utils;

#endregion

namespace mhxy.Client {

    /// <summary>
    /// </summary>
    public class DrawArgs {

        /// <summary>
        /// </summary>
        /// <param name="canvas"></param>
        /// <param name="priority"></param>
        public DrawArgs(Canvas canvas, DrawPriority priority) {
            CurrentCanvas = canvas;
            Priority = priority;
            switch (priority) {
                case DrawPriority.Lowest:
                    Bitmap = canvas.Lowest;
                    break;
                case DrawPriority.Lower:
                    Bitmap = canvas.Lower;
                    break;
                case DrawPriority.Normal:
                    Bitmap = canvas.Normal;
                    break;
                case DrawPriority.Higher:
                    Bitmap = canvas.Higher;
                    break;
                case DrawPriority.Highest:
                    Bitmap = canvas.Highest;
                    break;
            }

            FastBitmap = new FastBitmap(Bitmap);
        }

        /// <summary>
        ///     当前绘制的画布
        /// </summary>
        public Canvas CurrentCanvas { get; }

        /// <summary>
        ///     当前绘制优先级
        /// </summary>
        public DrawPriority Priority { get; }

        /// <summary>
        ///     当前绘制的bitmap
        /// </summary>
        public Bitmap Bitmap { get; }

        /// <summary>
        ///     Bitmap 包装可以对Bitmap进行快速操作
        /// </summary>
        public FastBitmap FastBitmap { get; }

        /// <summary>
        ///     画布宽度
        /// </summary>
        public int Width => CurrentCanvas.Width;

        /// <summary>
        ///     画布高度
        /// </summary>
        public int Height => CurrentCanvas.Height;

        /// <summary>
        ///     实际显示的世界区域
        /// </summary>
        public Point WorldPoint {
            get => CurrentCanvas.WorldPoint;
            set => CurrentCanvas.WorldPoint = value;
        }

    }

}