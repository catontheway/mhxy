// FileName:  DrawableBase.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180208 17:41
// Description:   

#region

using System;

#endregion

namespace mhxy.Client {

    /// <summary>
    /// </summary>
    public class DrawableBase : IDrawable {

        /// <summary>
        /// </summary>
        public DrawableBase() : this(DrawPriority.Normal) {
        }

        /// <summary>
        /// </summary>
        /// <param name="priority"></param>
        public DrawableBase(DrawPriority priority) {
            Priority = priority;
        }

        public DrawPriority Priority { get; }

        public virtual void NextFrame() {
            throw new NotImplementedException();
        }

        public virtual void Draw(DrawArgs args) {
            throw new NotImplementedException();
        }

    }

}