// FileName:  MainInterface.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 08:53
// Description:   

using mhxy.Client.Drawable;

namespace mhxy.Client.Interfaces {

    /// <summary>
    ///     游戏界面
    /// </summary>
    public class MainInterface : InterfaceBase {

        /// <summary>
        /// </summary>
        public override InterfaceType Type => InterfaceType.Main;

        private readonly DrawableMap _map = new DrawableMap();

        /// <summary>
        /// 
        /// </summary>
        protected override void ShowCore() {
            ServiceLocator.DrawingService.Add(_map);
        }

        /// <summary>
        /// 
        /// </summary>
        protected override void CloseCore() {
            ServiceLocator.DrawingService.Remove(_map);
        }
    }

}