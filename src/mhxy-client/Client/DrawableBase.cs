// FileName:  DrawableBase.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180208 17:41
// Description:   

#region

#endregion

namespace mhxy.Client {

    /// <summary>
    ///     可绘制对象基类
    /// </summary>
    public abstract class DrawableBase : IDrawable {

        /// <summary>
        ///     构造方法
        /// </summary>
        protected DrawableBase() : this(DrawPriority.Normal, 1) {
        }

        /// <summary>
        ///     构造方法
        /// </summary>
        /// <param name="priority">绘制级别</param>
        protected DrawableBase(DrawPriority priority) : this(priority, 1) {
            Priority = priority;
        }

        /// <summary>
        ///     构造方法
        /// </summary>
        /// <param name="priority">绘制级别</param>
        /// <param name="globalFramePerFrame">帧数调整</param>
        protected DrawableBase(DrawPriority priority, int globalFramePerFrame) {
            Priority = priority;
            _globalFramePerFrame = globalFramePerFrame;
        }

        private readonly int _globalFramePerFrame;

        private int _frameCount;

        /// <summary>
        ///     绘制级别
        /// </summary>
        public DrawPriority Priority { get; }

        /// <summary>
        ///     下一帧
        /// </summary>
        public void NextFrame() {
            if (++_frameCount < _globalFramePerFrame) {
                //没有达到切换画面条件
                return;
            }

            _frameCount = 0;
            NextFrameCore();
        }

        /// <summary>
        ///     绘制到画布上
        /// </summary>
        /// <param name="args"></param>
        public virtual void Draw(DrawArgs args) {
            DrawCore(args);
        }

        /// <summary>
        ///     钩子方法 派生类实现该方法 切换到下一帧
        /// </summary>
        protected abstract void NextFrameCore();

        /// <summary>
        ///     钩子方法 派生类实现该方法 绘制图像
        /// </summary>
        /// <param name="args"></param>
        protected abstract void DrawCore(DrawArgs args);

    }

}