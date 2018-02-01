using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows;
using mhxy.Logging;
using mhxy.Resource.Maps;
using SharpGL;
using SharpGL.Enumerations;
using SharpGL.SceneGraph;

namespace mhxy {

    /// <summary>
    /// SampleWindow.xaml 的交互逻辑
    /// </summary>
    public partial class SampleWindow {
        public SampleWindow() {
            InitializeComponent();
            _logger = LogManager.GetLogger(this);
            _logger.Info("Create Main Window");
            ServiceLocator.MapManager.TryGetMap("1501", out Map map);
        }

        private readonly ILogger _logger;

        private void SharpglCtrl_OnOpenGLDraw(object sender, OpenGLEventArgs args) {
            //_logger.Debug("OnOpenGLDraw");
            //Test1();
            //Test2();
        }

        private void Test1() {
            var gl = SharpglCtrl.OpenGL;
            gl.Clear(OpenGL.GL_COLOR_BUFFER_BIT | OpenGL.GL_DEPTH_BUFFER_BIT);
            gl.PointSize(3.0f);
            gl.Color(RandomFloat(), RandomFloat(), RandomFloat());
            //gl.Color(255, 0, 0);
            gl.Begin(BeginMode.LineLoop);
            gl.Vertex(RandomFloat() * SharpglCtrl.ActualWidth, RandomFloat() * SharpglCtrl.ActualHeight, 0);
            gl.Vertex(RandomFloat() * SharpglCtrl.ActualWidth, RandomFloat() * SharpglCtrl.ActualHeight, 0);
            gl.End();
        }

        private void Tick() {
            _shapes.SelectMany(s => s.Points).ToList().ForEach(sp => ApplyVelocity(ref sp.Position, ref sp.Velocity));
        }

        private void ApplyVelocity(ref Vertex position, ref Vertex velocity) {
            var newX = position.X + velocity.X;
            if (newX < 0) {
                position.X = -newX;
                velocity.X *= -1;
            } else if (newX > SharpglCtrl.ActualWidth) {
                position.X -= (newX - (float)SharpglCtrl.ActualWidth);
                velocity.X *= -1;
            } else {
                position.X = newX;
            }

            var newy = position.Y + velocity.Y;
            if (newy < 0) {
                position.Y = -newy;
                velocity.Y *= -1;
            } else if (newy > SharpglCtrl.ActualHeight) {
                position.Y -= (newy - (float)SharpglCtrl.ActualHeight);
                velocity.Y *= -1;
            } else {
                position.Y = newy;
            }
        }

        private void CreateShapes() {
            //  Create some shapes...
            var shapeCount = _random.Next(2, 5);
            for (var i = 0; i < shapeCount; i++) {
                //  Create the shape.
                var shape = new CrazyShape { Red = RandomFloat(), Green = RandomFloat(), Blue = RandomFloat() };

                //  Create the points.
                var pointCount = _random.Next(3, 6);
                for (var j = 0; j < pointCount; j++)
                    shape.Points.Add(new ShapePoint {
                        Position = new Vertex(RandomFloat() * (float)SharpglCtrl.ActualWidth,
                                                 RandomFloat() * (float)SharpglCtrl.ActualHeight, 0),
                        Velocity = new Vertex(RandomFloat(1f, 10f), RandomFloat(1f, 10f), 0)
                    });
                //  Add the shape.
                _shapes.Add(shape);
            }
        }

        private float RandomFloat(float min = 0, float max = 1) {
            return (float)_random.NextDouble() * (max - min) + min;
        }

        public double GetRandomNumber(double minimum, double maximum) {
            var random = new Random();
            return random.NextDouble() * (maximum - minimum) + minimum;
        }

        private readonly Random _random = new Random();

        private readonly List<CrazyShape> _shapes = new List<CrazyShape>();

        private void Button_Click(object sender, RoutedEventArgs e) {
            _shapes.Clear();
        }

        private void SharpglCtrl_OnOpenGLInitialized(object sender, OpenGLEventArgs args) {
            //_logger.Debug("OnOpenGLInitialized");
        }

        private void SharpglCtrl_OnResized(object sender, OpenGLEventArgs args) {
            //_logger.Debug("OnResized");
            //  Get the OpenGL instance.
            var gl = args.OpenGL;
            //  Create an orthographic projection.
            gl.MatrixMode(MatrixMode.Projection);
            gl.LoadIdentity();
            gl.Ortho(0, SharpglCtrl.ActualWidth, SharpglCtrl.ActualHeight, 0, -10, 10);
            //  Back to the modelview.
            gl.MatrixMode(MatrixMode.Modelview);
        }

        private void Test2() {
            //  If there aren't any shapes, create them.
            if (!_shapes.Any()) {
                CreateShapes();
            }
            //  Get the OpenGL instance.
            var gl = SharpglCtrl.OpenGL;
            gl.Clear(OpenGL.GL_COLOR_BUFFER_BIT | OpenGL.GL_DEPTH_BUFFER_BIT);
            gl.PointSize(3.0f);
            foreach (var shape in _shapes) {
                gl.Color(shape.Red, shape.Green, shape.Blue);
                //gl.Color(255, 0, 0);
                gl.Begin(BeginMode.LineLoop);
                shape.Points.ForEach(sp => gl.Vertex(sp.Position));
                gl.End();
            }
            Tick();
        }

    }

    public class CrazyShape {
        public List<ShapePoint> Points = new List<ShapePoint>();
        public float Red;
        public float Green;
        public float Blue;
    }

    public class ShapePoint {
        public Vertex Position;
        public Vertex Velocity;
    }
}
