using mhxy.Logging;
using SharpGL;
using SharpGL.SceneGraph;

namespace mhxy {
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow {

        private readonly ILogger _logger;

        public MainWindow() {
            InitializeComponent();
            _logger = LogManager.GetLogger(this);
            _logger.Info("Create Main Window");
        }

        private void SharpglCtrl_OnOpenGLDraw(object sender, OpenGLEventArgs args) {
            _logger.Info("SharpglCtrl_OnOpenGLDraw");
        }

        private void SharpglCtrl_OnOpenGLInitialized(object sender, OpenGLEventArgs args) {
            _logger.Info("SharpglCtrl_OnOpenGLInitialized");
         
        }

        private void SharpglCtrl_OnResized(object sender, OpenGLEventArgs args) {
            _logger.Info("SharpglCtrl_OnResized");
           
        }

    }
}
