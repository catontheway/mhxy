// FileName:  MainInterface.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 08:53
// Description:   

#region

using mhxy.Client.Drawable;

#endregion

namespace mhxy.Client.Interfaces {

    /// <summary>
    ///     游戏界面
    /// </summary>
    public class MainInterface : InterfaceBase {

        private readonly DrawableMap _map = new DrawableMap();
        private readonly DrawableCurrentPlayer _currentUser = new DrawableCurrentPlayer();

        /// <summary>
        /// 主界面
        /// </summary>
        public override InterfaceType Type => InterfaceType.Main;

        /// <summary>
        /// 显示
        /// </summary>
        protected override void ShowCore() {
            ServiceLocator.DrawingService.Add(_map);
            ServiceLocator.DrawingService.Add(_currentUser);
        }

        /// <summary>
        /// 关闭
        /// </summary>
        protected override void CloseCore() {
            ServiceLocator.DrawingService.Remove(_currentUser);
            ServiceLocator.DrawingService.Remove(_map);
        }

    }

}