// FileName:  DrawableMap.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 13:57
// Description:   

#region

using System.Drawing;
using mhxy.NetEase.Maps;
using mhxy.Utils;

#endregion

namespace mhxy.Client.MainDrawable {

    /// <summary>
    ///     地图绘制
    /// </summary>
    public class DrawableMap : DrawableBase {

        /// <summary>
        ///     地图绘制
        /// </summary>
        public DrawableMap() : base(DrawPriority.Lowest) {
        }

        private Rectangle _currentRectangle = new Rectangle(0, 0, Global.Width, Global.Height); // 绘制大小
        private string _currentMapId; //当前地图Id
        private Map _currentMap; //当前地图数据

        /// <summary>
        ///     切换到下一帧
        /// </summary>
        public override void NextFrame() {
            // 获取场景 & 地图 &
            var currentScene = ServiceLocator.ClientEngine.GetCurrentScene();
            if (!string.Equals(_currentMapId, currentScene.MapId)) {
                _currentMapId = currentScene.MapId;
                ServiceLocator.MapManager.TryGetMap(_currentMapId, out _currentMap);
            }

            if (_currentMap == null) {
                return;
            }

            //主角
            var currentPlayer = ServiceLocator.ClientEngine.GetCurrentPlayer();
            // 计算主角所在位置 从而得到应该将哪部分地图显示在界面上 
            // 得到的X Y 分别是 显示在界面上地图的左上角坐标
            int x = currentPlayer.At.X - Global.PlayX;
            x = x < 0 ? 0 : (x > _currentMap.MaxX ? _currentMap.MaxX : x);
            _currentRectangle.X = x;
            int y = currentPlayer.At.Y - Global.PlayY;
            y = y < 0 ? 0 : (y > _currentMap.MaxY ? _currentMap.MaxY : y);
            _currentRectangle.Y = y;
        }

        public override void Draw(DrawArgs args) {
            if (_currentMap == null) {
                return;
            }

            // 绘制地图
            args.FastBitmap.Lock();
            args.FastBitmap.CopyRegion(_currentMap.Bitmap, _currentRectangle,
                new Rectangle(0, 0, args.Width, args.Height));
            args.FastBitmap.Unlock();
            //绘制遮罩层
            FastBitmap fastBitmap = new FastBitmap(args.CurrentCanvas.Normal);
            fastBitmap.Lock();
            fastBitmap.CopyRegion(_currentMap.MaskBitmap, _currentRectangle,
                new Rectangle(0, 0, args.Width, args.Height));
            fastBitmap.Unlock();
            //设置世界坐标
            args.WorldPoint = new Point(_currentRectangle.X, _currentRectangle.Y);
        }

    }

}