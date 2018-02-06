﻿// FileName:  DrawingService.cs
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

        public Canvas Draw() {
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