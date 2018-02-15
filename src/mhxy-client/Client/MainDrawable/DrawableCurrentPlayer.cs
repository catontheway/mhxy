// FileName:  DrawableCurrentPlayer.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180206 14:36
// Description:   

#region

using System.Drawing;
using mhxy.Common.Model;
using mhxy.NetEase.Wass;
using mhxy.Utils;

#endregion

namespace mhxy.Client.MainDrawable {

    /// <summary>
    ///     主角绘制
    /// </summary>
    public class DrawableCurrentPlayer : DrawableBase {

        private const int TotalFrame = 8; //人物动画8帧一组
        private const int FramePerSecond = 10; //播放速度
        private static readonly int GlobalFramePerFrame = Global.FramePerSecond / FramePerSecond; //实际播放速度根据全局画面速度计算

        public DrawableCurrentPlayer() : base(DrawPriority.Lower) {
        }

        private int _frameCount;

        private SpWas _walk;
        private SpWas _stand;
        private CurrentPlayer _currentPlayer;
        private int _frameIndex;
        private SpFrame _frame;
        private SpHeader _header;

        public override void NextFrame() {
            if (++_frameCount < GlobalFramePerFrame) {
                //没有达到切换画面条件
                return;
            }

            _frameCount = 0;
            _currentPlayer = ServiceLocator.ClientEngine.GetCurrentPlayer();
            if (_walk == null) {
                ServiceLocator.WasManager.TryGetSpWas("shape.wdf", 0x54F3FC94, out _walk);
            }

            if (_stand == null) {
                ServiceLocator.WasManager.TryGetSpWas("shape.wdf", 0x49386FCE, out _stand);
            }

            if (_walk == null || _stand == null || _currentPlayer == null) {
                return;
            }

            //计算显示哪一帧
            _frameIndex = (_frameIndex + 1) % TotalFrame;
            _frame = _currentPlayer.Moving
                ? _walk.GetFrame((int) _currentPlayer.FaceTo, _frameIndex)
                : _stand.GetFrame((int) _currentPlayer.FaceTo, _frameIndex);
            _header = _currentPlayer.Moving ? _walk.SpHeader : _stand.SpHeader;
        }

        public override void Draw(DrawArgs args) {
            //空值检测
            if (_frame == null || _header == null || _currentPlayer == null) {
                return;
            }

            //计算显示位置
            var currentPlayerX = _currentPlayer.At.X;
            var currentPlayerY = _currentPlayer.At.Y;
            var worldPointX = args.WorldPoint.X;
            var worldPointY = args.WorldPoint.Y;
            var sourceRect = new Rectangle(0, 0, _header.Width, _header.Height);
            int targX = currentPlayerX - worldPointX - _header.KeyX;
            int targY = currentPlayerY - worldPointY - _header.KeyY;
            var targetRect = new Rectangle(targX, targY, _header.Width, _header.Height);
            //将图像复制到画布 : args.FastBitmap
            FastBitmap fastBitmap = args.FastBitmap;
            fastBitmap.Lock();
            fastBitmap.CopyRegion(_frame.Bitmap, sourceRect, targetRect);
            fastBitmap.Unlock();
        }

    }

}