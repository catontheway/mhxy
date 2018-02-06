// FileName:  DrawableCurrentPlayer.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180206 14:36
// Description:   

#region

using System;
using mhxy.Common.Model;
using mhxy.Resource.Wass;

#endregion

namespace mhxy.Client.Drawable {

    /// <summary>
    ///     主角绘制
    /// </summary>
    public class DrawableCurrentPlayer : IDrawable {

        private Was _walk;

        private CurrentPlayer _currentPlayer;

        /// <summary>
        ///     是否是静态资源
        /// </summary>
        public bool Static {
            get => false;
            set => throw new NotImplementedException();
        }

        public void NextFrame() {
            _currentPlayer = ServiceLocator.ClientEngine.GetCurrentPlayer();
            if (_walk == null) {
                ServiceLocator.WasManager.TryGetWas("shape.wdf", 0X54F3FC94, out _walk);
            }
        }

        public void Frame(int frame) {

        }

        public void Draw(Canvas cancas) {
        }

    }

}