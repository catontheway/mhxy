// FileName:  MhxyGameWindow.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180205 13:58
// Description:   

#region

using System.Drawing;
using System.Drawing.Imaging;
using OpenTK;
using OpenTK.Graphics;
using OpenTK.Graphics.OpenGL;
using PixelFormat = System.Drawing.Imaging.PixelFormat;

#endregion

namespace mhxy.Client {

    /// <summary>
    ///     游戏窗口
    /// </summary>
    public class MhxyGameWindow : GameWindow {

        private int _texture;

        // private readonly ILogger _logger = ServiceLocator.GlobalLogger;

        #region

        private int _fpsCount;

        #endregion
        /// <summary>
        /// </summary>
        public new void Run() {
            Run(Global.FramePerSecond);
        }

        protected override void OnUpdateFrame(FrameEventArgs e) {
            //_logger.Debug($"OnUpdateFrame {e.Time}");
            ServiceLocator.DrawingService.UpdateFrame();
            base.OnUpdateFrame(e);
        }

        protected override void OnRenderFrame(FrameEventArgs e) {
            //_logger.Debug($"OnRenderFrame {e.Time}");
#if DEBUG
            _fpsCount++;
            if (_fpsCount == 60) {
                Title = $"(Vsync: {VSync}),FPS: {1f / e.Time:0}";
                _fpsCount = 0;
            }
#endif
            var oldTexture = _texture;
            var canvas = ServiceLocator.DrawingService.Draw();
            _texture = LoadTexture(canvas.Lowest);
            DrawImage(_texture);
            SwapBuffers();
            if (oldTexture != 0) {
                GL.DeleteTexture(_texture);
            }
            base.OnRenderFrame(e);
        }

        private static void DrawImage(int texture) {
            GL.Clear(ClearBufferMask.ColorBufferBit | ClearBufferMask.DepthBufferBit);
            GL.MatrixMode(MatrixMode.Projection);
            GL.LoadIdentity();
            GL.Ortho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
            GL.MatrixMode(MatrixMode.Modelview);
            GL.LoadIdentity();
            GL.Enable(EnableCap.Texture2D);
            GL.BindTexture(TextureTarget.Texture2D, texture);
            GL.Begin(PrimitiveType.Quads);
            GL.TexCoord2(0.0f, 1.0f);
            GL.Vertex2(-1.0f, -1.0f);
            GL.TexCoord2(1.0f, 1.0f);
            GL.Vertex2(1.0f, -1.0f);
            GL.TexCoord2(1.0f, 0.0f);
            GL.Vertex2(1.0f, 1.0f);
            GL.TexCoord2(0.0f, 0.0f);
            GL.Vertex2(-1.0f, 1.0f);
            GL.End();
        }

        private int LoadTexture(Bitmap bitmap) {
            GL.Hint(HintTarget.PerspectiveCorrectionHint, HintMode.Nicest);
            GL.GenTextures(1, out int texture);
            GL.BindTexture(TextureTarget.Texture2D, texture);
            BitmapData data = bitmap.LockBits(new Rectangle(0, 0, bitmap.Width, bitmap.Height),
                ImageLockMode.ReadOnly, PixelFormat.Format32bppArgb);
            GL.TexImage2D(TextureTarget.Texture2D, 0, PixelInternalFormat.Rgba, data.Width, data.Height, 0,
                OpenTK.Graphics.OpenGL.PixelFormat.Bgra, PixelType.UnsignedByte, data.Scan0);
            bitmap.UnlockBits(data);
            GL.TexParameter(TextureTarget.Texture2D, TextureParameterName.TextureMinFilter
                , (int)TextureMinFilter.Linear);
            GL.TexParameter(TextureTarget.Texture2D, TextureParameterName.TextureMagFilter
                , (int)TextureMagFilter.Linear);
            GL.TexParameter(TextureTarget.Texture2D, TextureParameterName.TextureWrapS, (int)TextureWrapMode.Repeat);
            GL.TexParameter(TextureTarget.Texture2D, TextureParameterName.TextureWrapT, (int)TextureWrapMode.Repeat);
            return texture;
        }

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

    }

}