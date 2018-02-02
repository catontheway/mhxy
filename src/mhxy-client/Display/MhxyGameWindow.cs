// FileName:  MhxyGameWindow.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 09:01
// Description:   

#region

using mhxy.Logging;
using OpenTK;
using OpenTK.Graphics;
using OpenTK.Graphics.OpenGL4;

#endregion

namespace mhxy.Display {

    /// <summary>
    ///     游戏窗口
    /// </summary>
    public class MhxyGameWindow : GameWindow {

        #region Ctor

        public MhxyGameWindow() {
        }

        public MhxyGameWindow(int width, int height)
            : base(width, height) {
        }

        public MhxyGameWindow(int width, int height, GraphicsMode mode)
            : base(width, height, mode) {
        }

        public MhxyGameWindow(int width, int height, GraphicsMode mode, string title)
            : base(width, height, mode, title) {
        }

        public MhxyGameWindow(int width, int height, GraphicsMode mode, string title, GameWindowFlags options)
            : base(width, height, mode, title, options) {
        }

        public MhxyGameWindow(int width, int height, GraphicsMode mode, string title, GameWindowFlags options
            , DisplayDevice device)
            : base(width, height, mode, title, options, device) {
        }

        public MhxyGameWindow(int width, int height, GraphicsMode mode, string title, GameWindowFlags options
            , DisplayDevice device, int major, int minor, GraphicsContextFlags flags)
            : base(width, height, mode, title, options, device, major, minor, flags) {
        }

        public MhxyGameWindow(int width, int height, GraphicsMode mode, string title, GameWindowFlags options
            , DisplayDevice device, int major, int minor, GraphicsContextFlags flags, IGraphicsContext sharedContext)
            : base(width, height, mode, title, options, device, major, minor, flags, sharedContext) {
        }

        #endregion

        private readonly ILogger _logger = ServiceLocator.GlobalLogger;

        /// <summary>
        /// 
        /// </summary>
        public new void Run() {
            Run(Environment.FramePerSecond);
        }

        protected override void OnUpdateFrame(FrameEventArgs e) {
            //_logger.Debug($"OnUpdateFrame {e.Time}");
            ServiceLocator.DrawingService.UpdateFrame();
            base.OnUpdateFrame(e);
        }

        protected override void OnRenderFrame(FrameEventArgs e) {
             //_logger.Debug($"OnUpdateFrame {e.Time}");
            Title = $"(Vsync: {VSync}) FPS: {1f / e.Time:0}";
            ServiceLocator.DrawingService.Draw();
            GL.Clear(ClearBufferMask.ColorBufferBit | ClearBufferMask.DepthBufferBit);
            SwapBuffers();
            base.OnRenderFrame(e);
        }

    }

}