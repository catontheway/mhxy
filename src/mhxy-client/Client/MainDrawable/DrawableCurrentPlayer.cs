// FileName:  DrawableCurrentPlayer.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180206 14:36
// Description:   

#region

using mhxy.Common.Model;
using mhxy.NetEase.Wass;
using mhxy.Utils;

#endregion

namespace mhxy.Client.MainDrawable {

    /// <summary>
    ///     主角绘制
    /// </summary>
    public class DrawableCurrentPlayer : DrawableBase {

        private const int ChangeFrame = 4;
        private const int TotalFrame = 8;

        public DrawableCurrentPlayer() : base(DrawPriority.Lowest) {
        }

        private SpWas _walk;
        private SpWas _stand;
        private CurrentPlayer _currentPlayer;
        private int _frame;
        private int _count;

        public override void NextFrame() {
            _currentPlayer = ServiceLocator.ClientEngine.GetCurrentPlayer();
            if (_walk == null) {
                ServiceLocator.WasManager.TryGetSpWas("shape.wdf", 0x54F3FC94, out _walk);
            }

            if (_stand == null) {
                ServiceLocator.WasManager.TryGetSpWas("shape.wdf", 0x49386FCE, out _stand);
            }

            if (_count++ >= ChangeFrame) {
                _count = 0;
                _frame = (_frame + 1) % TotalFrame;
            }
        }

        public override void Draw(DrawArgs args) {
            if (_walk == null || _stand == null || _currentPlayer == null) {
                return;
            }

            var frame = _currentPlayer.Moving
                ? _walk.GetFrame((int) _currentPlayer.FaceTo, _frame)
                : _stand.GetFrame((int) _currentPlayer.FaceTo, _frame);
            var header = _currentPlayer.Moving ? _walk.SpHeader : _stand.SpHeader;
            var currentPlayerX = _currentPlayer.At.X;
            var currentPlayerY = _currentPlayer.At.Y;
            var worldPointX = args.WorldPoint.X;
            var worldPointY = args.WorldPoint.Y;
            FastBitmap fastBitmap = args.FastBitmap;
            fastBitmap.Lock();
            using (FastBitmap play = new FastBitmap(frame.Bitmap)) {
                play.Lock();
                for (int x = 0; x < play.Width; x++) {
                    for (int y = 0; y < play.Height; y++) {
                        var pixel = play.GetPixel(x, y);
                        if (pixel != frame.ColorA0) {
                            // 画到Canvas上
                            int drawX = x + currentPlayerX - worldPointX - header.KeyX;
                            drawX = drawX > 0 ? drawX >= Global.Width ? Global.Width - 1 : drawX : 0;
                            int drawY = y + currentPlayerY - worldPointY - header.KeyY;
                            drawY = drawY > 0 ? drawY >= Global.Height ? Global.Height - 1 : drawY : 0;
                            fastBitmap.SetPixel(drawX, drawY, pixel);
                        }
                    }
                }

                play.Unlock();
            }

            fastBitmap.Unlock();
        }

    }

}