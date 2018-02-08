// FileName:  MainInterface.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 08:53
// Description:   

#region

using System;
using System.Drawing;
using mhxy.Client.Drawable;
using mhxy.Common.Model;

#endregion

namespace mhxy.Client.Interfaces {

    /// <summary>
    ///     游戏界面
    /// </summary>
    public class MainInterface : InterfaceBase {

        private readonly DrawableMap _map = new DrawableMap();
        private readonly DrawableCurrentPlayer _currentUser = new DrawableCurrentPlayer();

        private Point _goto = Point.Empty;

        /// <summary>
        /// 主界面
        /// </summary>
        public override InterfaceType Type => InterfaceType.Main;

        /// <summary>
        /// 显示
        /// </summary>
        protected override void ShowCore() {
            ServiceLocator.ScheduleService.AddJob(() => {
                var currentPlayer = ServiceLocator.ClientEngine.GetCurrentPlayer();
                if (_goto == Point.Empty) {
                    ServiceLocator.ClientEngine.GetCurrentPlayer().Moving = false;
                } else {
                    var distX = _goto.X - currentPlayer.At.X;
                    var distY = _goto.Y - currentPlayer.At.Y;
                    if (!CalcSpeedAndDir(distX, distY, out int speetX, out int speedY, out Direction direction)) {
                        currentPlayer.At = _goto;
                        _goto = Point.Empty;
                    } else {
                        var newPoint = new Point {
                            X = currentPlayer.At.X + speetX,
                            Y = currentPlayer.At.Y + speedY
                        };
                        currentPlayer.FaceTo = direction;
                        currentPlayer.At = newPoint;
                        currentPlayer.Moving = true;
                    }
                }
            }, schedule => schedule.ToRunEvery(20).Milliseconds());
            ServiceLocator.DrawingService.Add(_map);
            ServiceLocator.DrawingService.Add(_currentUser);
            ServiceLocator.GameWindow.MouseDown += GameWindow_MouseDown;
            ServiceLocator.GameWindow.KeyDown += GameWindow_KeyDown;
        }

        private bool CalcSpeedAndDir(int distX, int distY, out int speetX, out int speedY, out Direction direction) {
            speetX = speedY = 0;
            direction = Direction.Left;
            var distX2 = distX * distX;
            var distY2 = distY * distY;
            var dist = Math.Sqrt(distX2 + distY2);
            var step = (int)(dist / 5);
            if (step < 1) {
                return false;
            }
            speetX = distX / step;
            speedY = distY / step;
            if (distX2 >= distY2 * 4) {
                direction = distX <= 0 ? Direction.Left : Direction.Right;
                return true;
            }
            if (distY2 >= distX2 * 4) {
                direction = distY <= 0 ? Direction.Up : Direction.Down;
                return true;
            }
            if (distX < 0) {
                direction = distY <= 0 ? Direction.LeftUp : Direction.LeftDown;
                return true;
            }
            direction = distY <= 0 ? Direction.RightUp : Direction.RightDown;
            return true;
        }

        private void GameWindow_KeyDown(object sender, OpenTK.Input.KeyboardKeyEventArgs e) {

        }

        private void GameWindow_MouseDown(object sender, OpenTK.Input.MouseButtonEventArgs e) {
            var canvas = ServiceLocator.DrawingService.GetCurrentCanvas();
            _goto = new Point(canvas.WorldPoint.X + e.X, canvas.WorldPoint.Y + e.Y);
        }

        /// <summary>
        /// 关闭
        /// </summary>
        protected override void CloseCore() {
            ServiceLocator.GameWindow.KeyDown -= GameWindow_KeyDown;
            ServiceLocator.GameWindow.MouseDown -= GameWindow_MouseDown;
            ServiceLocator.DrawingService.Remove(_currentUser);
            ServiceLocator.DrawingService.Remove(_map);
        }

    }

}