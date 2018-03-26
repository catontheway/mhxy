// FileName:  DrawingService.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180205 13:58
// Description:   

#region

using System;
using System.Collections.Generic;
using mhxy.Common;

#endregion

namespace mhxy.Client {

    /// <summary>
    /// 绘制服务
    /// </summary>
    public class DrawingService : ServiceBase, IDrawingService {

        /// <summary>
        /// 绘制服务
        /// </summary>
        public DrawingService() {
            _canvas = new Canvas(Global.Width, Global.Height);
            _drawables[DrawPriority.Lowest] = new List<IDrawable>();
            _drawables[DrawPriority.Lower] = new List<IDrawable>();
            _drawables[DrawPriority.Normal] = new List<IDrawable>();
            _drawables[DrawPriority.Higher] = new List<IDrawable>();
            _drawables[DrawPriority.Highest] = new List<IDrawable>();
        }

        private readonly Dictionary<DrawPriority, List<IDrawable>> _drawables =
            new Dictionary<DrawPriority, List<IDrawable>>();//绘制对象

        private Canvas _canvas;//画布

        private bool _drawing;// 是否正在绘制

        /// <summary>
        /// 添加绘制对象
        /// </summary>
        /// <param name="drawableObj"></param>
        public void Add(IDrawable drawableObj) {
            _drawables[drawableObj.Priority].Add(drawableObj);
        }

        /// <summary>
        /// 移除绘制对象
        /// </summary>
        /// <param name="drawableObj"></param>
        public void Remove(IDrawable drawableObj) {
            _drawables[drawableObj.Priority].Remove(drawableObj);
        }

        /// <summary>
        /// 获取当前画布
        /// </summary>
        /// <returns></returns>
        public Canvas GetCurrentCanvas() {
            return _canvas;
        }

        /// <summary>
        /// 绘制并返回绘制后的画布
        /// </summary>
        /// <returns></returns>
        public Canvas Draw() {
            if (!_drawing) {
                _drawing = true;
                var canvas = new Canvas(Global.Width, Global.Height);
                var priority = DrawPriority.Lowest;
                _drawables[priority].ForEach(drawable => drawable.Draw(new DrawArgs(canvas, priority)));
                priority = DrawPriority.Lower;
                _drawables[priority].ForEach(drawable => drawable.Draw(new DrawArgs(canvas, priority)));
                priority = DrawPriority.Normal;
                _drawables[priority].ForEach(drawable => drawable.Draw(new DrawArgs(canvas, priority)));
                priority = DrawPriority.Higher;
                _drawables[priority].ForEach(drawable => drawable.Draw(new DrawArgs(canvas, priority)));
                priority = DrawPriority.Highest;
                _drawables[priority].ForEach(drawable => drawable.Draw(new DrawArgs(canvas, priority)));
                _canvas = canvas;
                _drawing = false;
            }

            return _canvas;
        }

        /// <summary>
        /// 更新画面
        /// </summary>
        public void UpdateFrame() {
            OnBeforeFrame();
            var priority = DrawPriority.Lowest;
            _drawables[priority].ForEach(drawable => drawable.NextFrame());
            priority = DrawPriority.Lower;
            _drawables[priority].ForEach(drawable => drawable.NextFrame());
            priority = DrawPriority.Normal;
            _drawables[priority].ForEach(drawable => drawable.NextFrame());
            priority = DrawPriority.Higher;
            _drawables[priority].ForEach(drawable => drawable.NextFrame());
            priority = DrawPriority.Highest;
            _drawables[priority].ForEach(drawable => drawable.NextFrame());
        }

        /// <summary>
        /// 更新画面前事件
        /// </summary>
        public event EventHandler BeforeFrame;

        /// <summary>
        /// 移除所有绘制对象
        /// </summary>
        public void RemoveAll() {
            RemoveAll(DrawPriority.Lowest);
            RemoveAll(DrawPriority.Lower);
            RemoveAll(DrawPriority.Normal);
            RemoveAll(DrawPriority.Higher);
            RemoveAll(DrawPriority.Highest);
        }

        /// <summary>
        /// 移除某个绘制对象
        /// </summary>
        /// <param name="priority"></param>
        private void RemoveAll(DrawPriority priority) {
            _drawables[priority].Clear();
        }

        /// <summary>
        /// Trigger Event
        /// </summary>
        protected virtual void OnBeforeFrame() {
            BeforeFrame?.Invoke(this, EventArgs.Empty);
        }

    }

}