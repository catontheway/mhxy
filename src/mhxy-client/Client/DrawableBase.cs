// FileName:  DrawableBase.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180208 17:41
// Description:   

#region

using System;

#endregion

namespace mhxy.Client {

    /// <summary>
    ///     可绘制对象基类
    /// </summary>
    public class DrawableBase : IDrawable {

        /// <summary>
        /// </summary>
        public DrawableBase() : this(DrawPriority.Normal) {
        }

        /// <summary>
        /// </summary>
        /// <param name="priority">绘制级别</param>
        public DrawableBase(DrawPriority priority) {
            Priority = priority;
        }

        /// <summary>
        ///     绘制级别
        /// </summary>
        public DrawPriority Priority { get; }

        /// <summary>
        ///     下一帧
        /// </summary>
        public virtual void NextFrame() {
            throw new NotImplementedException();
        }

        /// <summary>
        ///     绘制到画布上
        /// </summary>
        /// <param name="args"></param>
        public virtual void Draw(DrawArgs args) {
            throw new NotImplementedException();
        }

    }

}