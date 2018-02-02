// FileName:  DrawingService.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 08:53
// Description:   

#region

using System.Collections.Generic;
using mhxy.Common;

#endregion

namespace mhxy.Display {

    /// <summary>
    /// </summary>
    public class DrawingService : ServiceBase, IDrawingService {

        private readonly List<IDrawable> _drawables = new List<IDrawable>();

        private readonly byte[] _canvas = new byte[Environment.Width * Environment.Height];

        public void Add(IDrawable drawableObj) {
            _drawables.Add(drawableObj);
        }

        public void Remove(IDrawable drawableObj) {
            _drawables.Remove(drawableObj);
        }

        public byte[] Draw() {
            _drawables.ForEach(drawable => drawable.Draw(_canvas));
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