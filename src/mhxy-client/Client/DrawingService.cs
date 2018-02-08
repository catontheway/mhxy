// FileName:  DrawingService.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180205 13:58
// Description:   

#region

using System.Collections.Generic;
using mhxy.Common;

#endregion

namespace mhxy.Client {

    /// <summary>
    /// </summary>
    public class DrawingService : ServiceBase, IDrawingService {

        /// <summary>
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
            new Dictionary<DrawPriority, List<IDrawable>>();

        private readonly Canvas _canvas;

        public void Add(IDrawable drawableObj) {
            _drawables[drawableObj.Priority].Add(drawableObj);
        }

        public void Remove(IDrawable drawableObj) {
            _drawables[drawableObj.Priority].Remove(drawableObj);
        }

        public Canvas GetCurrentCanvas() {
            return _canvas;
        }

        public Canvas Draw() {
            var priority = DrawPriority.Lowest;
            _drawables[priority].ForEach(drawable => drawable.Draw(new DrawArgs(_canvas, priority)));
            priority = DrawPriority.Lower;
            _drawables[priority].ForEach(drawable => drawable.Draw(new DrawArgs(_canvas, priority)));
            priority = DrawPriority.Normal;
            _drawables[priority].ForEach(drawable => drawable.Draw(new DrawArgs(_canvas, priority)));
            priority = DrawPriority.Higher;
            _drawables[priority].ForEach(drawable => drawable.Draw(new DrawArgs(_canvas, priority)));
            priority = DrawPriority.Highest;
            _drawables[priority].ForEach(drawable => drawable.Draw(new DrawArgs(_canvas, priority)));
            return _canvas;
        }

        public void UpdateFrame() {
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

        public void RemoveAll() {
            RemoveAll(DrawPriority.Lowest);
            RemoveAll(DrawPriority.Lower);
            RemoveAll(DrawPriority.Normal);
            RemoveAll(DrawPriority.Higher);
            RemoveAll(DrawPriority.Highest);
        }

        private void RemoveAll(DrawPriority priority) {
            _drawables[priority].Clear();
        }

    }

}