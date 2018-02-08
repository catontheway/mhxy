// FileName:  DrawableCurrentPlayer.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180206 14:36
// Description:   

#region

using System;
using mhxy.Common.Model;
using mhxy.Resource.Wass;
using mhxy.Utils;

#endregion

namespace mhxy.Client.Drawable {

    /// <summary>
    ///     主角绘制
    /// </summary>
    public class DrawableCurrentPlayer : IDrawable {

        private SpWas _walk;
        private SpWas _stand;
        private CurrentPlayer _currentPlayer;
        private int _frame = 8;

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
                ServiceLocator.WasManager.TryGetSpWas("shape.wdf", 0x54F3FC94, out _walk);
                //_walk.Save();
            }
            if (_stand == null) {
                ServiceLocator.WasManager.TryGetSpWas("shape.wdf", 0x49386FCE, out _stand);
                //_stand.Save();
            }
            _frame = (_frame + 1) % 32;
        }

        public void Frame(int frame) {

        }

        public void Draw(Canvas cancas) {
            if (_walk == null || _stand == null || _currentPlayer == null) {
                return;
            }
            var frame = _currentPlayer.Moving ? _walk.GetFrame((int)_currentPlayer.FaceTo, _frame / 4) : _stand.GetFrame((int)_currentPlayer.FaceTo, _frame / 4);
            using (FastBitmap canvas = new FastBitmap(cancas.Bitmap)) {
                canvas.Lock();
                using (FastBitmap play = new FastBitmap(frame.Bitmap)) {
                    play.Lock();
                    for (int x = 0; x < play.Width; x++) {
                        for (int y = 0; y < play.Height; y++) {
                            var pixel = play.GetPixel(x, y);
                            if (pixel != frame.ColorA0) {
                                // 画到Canvas上
                                int drawX = x + _currentPlayer.At.X - cancas.WorldPoint.X;
                                drawX = drawX > 0 ? drawX >= Global.Width ? Global.Width - 1 : drawX : 0;
                                int drawY = y + _currentPlayer.At.Y - cancas.WorldPoint.Y;
                                drawY = drawY > 0 ? drawY >= Global.Height ? Global.Height - 1 : drawY : 0;
                                canvas.SetPixel(drawX, drawY, pixel);
                            }
                        }
                    }
                    play.Unlock();
                }
                canvas.Unlock();
            }
        }
    }
}