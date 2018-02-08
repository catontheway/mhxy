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

        public DrawingService() {
            _canvas = new Canvas(Global.Width, Global.Height);
        }

        private readonly List<IDrawable> _drawables = new List<IDrawable>();
        private readonly Canvas _canvas;

        public void Add(IDrawable drawableObj) {
            _drawables.Add(drawableObj);
        }

        public void Remove(IDrawable drawableObj) {
            _drawables.Remove(drawableObj);
        }

        public Canvas GetCurrentCanvas() {
            return _canvas;
        }

        public Canvas Draw() {
            //Canvas canvas = new Canvas(Global.Width, Global.Height);
            _drawables.ForEach(drawable => drawable.Draw(_canvas));
            //using (ImageFactory factory = new ImageFactory()) {
            //    factory.Load(canvas.Bitmap).Save(Path.Combine(Environment.CurrentDirectory, DateTime.Now.Ticks + ".bmp"));
            //}
            return _canvas;
        }

        public void UpdateFrame() {
            _drawables.ForEach(drawable => drawable.NextFrame());
        }

        public void RemoveAll() {
            _drawables.Clear();
        }

    }

}