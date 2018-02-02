// FileName:  SceneDisplay.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 13:54
// Description:   

using mhxy.Display;
using mhxy.Logging;
using mhxy.Resource.Maps;

namespace mhxy.Client.Drawable {

    /// <summary>
    /// 供绘制的场景
    /// </summary>
    public class DrawableMap : IDrawable {

        private string _currentMapId;
        private Map _currentMap;
        //private int _centerX;
        //private int _centerY;
        private readonly ILogger _logger = ServiceLocator.GlobalLogger;

        public bool Static { get; set; }

        public void NextFrame() {
            var currentScene = ServiceLocator.ClientEngine.GetCurrentScene();
            if (!string.Equals(_currentMapId, currentScene.MapId)) {
                _currentMapId = currentScene.MapId;
                ServiceLocator.MapManager.TryGetMap(_currentMapId, out _currentMap);
            }
        }

        public void Frame(int frame) {
            throw new System.NotImplementedException();
        }

        public void Draw(byte[] cancas) {

        }

    }

}