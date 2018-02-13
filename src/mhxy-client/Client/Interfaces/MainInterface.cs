// FileName:  MainInterface.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 08:53
// Description:   

#region

using System.Drawing;
using mhxy.Client.MainDrawable;
using OpenTK.Input;

#endregion

namespace mhxy.Client.Interfaces {

    /// <summary>
    ///     游戏界面
    /// </summary>
    public class MainInterface : InterfaceBase {

        private readonly DrawableMap _map = new DrawableMap();
        private readonly DrawableCurrentPlayer _currentUser = new DrawableCurrentPlayer();

        //private Point _goto = Point.Empty;

        /// <summary>
        ///     主界面
        /// </summary>
        public override InterfaceType Type => InterfaceType.Main;

        /// <summary>
        ///     显示
        /// </summary>
        protected override void ShowCore() {
            ServiceLocator.DrawingService.Add(_map);
            ServiceLocator.DrawingService.Add(_currentUser);
            ServiceLocator.Window.MouseDown += GameWindow_MouseDown;
            ServiceLocator.Window.KeyDown += GameWindow_KeyDown;
        }


        private void GameWindow_KeyDown(object sender, KeyboardKeyEventArgs e) {
        }

        private void GameWindow_MouseDown(object sender, MouseButtonEventArgs e) {
            var canvas = ServiceLocator.DrawingService.GetCurrentCanvas();
            var gotoPoint = new Point(canvas.WorldPoint.X + e.X, canvas.WorldPoint.Y + e.Y);
            ServiceLocator.ClientEngine.WalkTo(gotoPoint);
        }

        /// <summary>
        ///     关闭
        /// </summary>
        protected override void CloseCore() {
            ServiceLocator.Window.KeyDown -= GameWindow_KeyDown;
            ServiceLocator.Window.MouseDown -= GameWindow_MouseDown;
            ServiceLocator.DrawingService.Remove(_currentUser);
            ServiceLocator.DrawingService.Remove(_map);
        }

    }

}