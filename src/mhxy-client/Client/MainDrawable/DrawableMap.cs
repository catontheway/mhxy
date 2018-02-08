// FileName:  DrawableMap.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 13:57
// Description:   

#region

using System.Drawing;
using mhxy.Resource.Maps;
using mhxy.Utils;

#endregion

namespace mhxy.Client.Drawable {

    /// <summary>
    ///     供绘制的场景
    /// </summary>
    public class DrawableMap : IDrawable {

        private Rectangle _currentRectangle = new Rectangle(0, 0, Global.Width, Global.Height);
        private string _currentMapId;
        private Map _currentMap;

        public void NextFrame() {
            var currentScene = ServiceLocator.ClientEngine.GetCurrentScene();
            var currentPlayer = ServiceLocator.ClientEngine.GetCurrentPlayer();
            if (!string.Equals(_currentMapId, currentScene.MapId)) {
                _currentMapId = currentScene.MapId;
                ServiceLocator.MapManager.TryGetMap(_currentMapId, out _currentMap);
                //_currentMap.Save();
            }
            int x = currentPlayer.At.X - Global.PlayX;
            x = x < 0 ? 0 : (x > _currentMap.MaxX ? _currentMap.MaxX : x);
            _currentRectangle.X = x;
            int y = currentPlayer.At.Y - Global.PlayY;
            y = y < 0 ? 0 : (y > _currentMap.MaxY ? _currentMap.MaxY : y);
            _currentRectangle.Y = y;
        }

        public void Draw(Canvas canvas) {
            if (_currentMap == null) {
                return;
            }
            FastBitmap.CopyRegion(_currentMap.Bitmap, canvas.Bitmap,
                _currentRectangle,
                new Rectangle(0, 0, canvas.Width, canvas.Height));
            canvas.WorldPoint = new Point(_currentRectangle.X, _currentRectangle.Y);
        }
    }

}