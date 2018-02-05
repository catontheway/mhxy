// FileName:  SceneDisplay.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 13:54
// Description:   

using System;
using System.Drawing;
using mhxy.Logging;
using mhxy.Resource.Maps;

namespace mhxy.Client.Drawable {

    /// <summary>
    /// 供绘制的场景
    /// </summary>
    public class DrawableMap : IDrawable {

        private readonly ILogger _logger = ServiceLocator.GlobalLogger;
        private Rectangle _currentRectangle = new Rectangle(0, 0, Global.Width, Global.Height);
        private string _currentMapId;
        private Map _currentMap;

        public bool Static { get; set; }

        private static readonly Random Rand = new Random();

        public void NextFrame() {
            var currentScene = ServiceLocator.ClientEngine.GetCurrentScene();
            if (!string.Equals(_currentMapId, currentScene.MapId)) {
                _currentMapId = currentScene.MapId;
                ServiceLocator.MapManager.TryGetMap(_currentMapId, out _currentMap);
                _currentMap.Save();
            }
            _currentRectangle.X = currentScene.PlayerX;
            _currentRectangle.Y = currentScene.PlayerY;
        }

        public void Frame(int frame) {

        }

        public void Draw(Canvas canvas) {
            if (_currentMap == null) {
                return;
            }
            FastBitmap.CopyRegion(_currentMap.Bitmap, canvas.Bitmap,
                _currentRectangle,
                new Rectangle(0, 0, canvas.Width, canvas.Height));
        }
    }

}