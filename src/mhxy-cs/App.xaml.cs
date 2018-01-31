using System.Windows;
using mhxy.Log4Net;
using mhxy.Logging;

namespace mhxy {
    /// <summary>
    /// App.xaml 的交互逻辑
    /// </summary>
    public partial class App {

        private ILogger _logger;

        protected override void OnStartup(StartupEventArgs e) {
            base.OnStartup(e);
            LogManager.AddLoggerAdapter(new Log4NetLoggerAdapter());
            _logger = LogManager.GetLogger(this);
            _logger.Debug("App Startup");
            InitializeServices();
        }

        protected override void OnExit(ExitEventArgs e) {
            base.OnExit(e);
            _logger.Debug("App Exit");
        }

        private void InitializeServices() {
            
        }

    }
}
