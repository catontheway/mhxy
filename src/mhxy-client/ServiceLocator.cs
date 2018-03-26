// FileName:  ServiceLocator.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 08:53
// Description:   

#region

using System;
using System.Windows.Forms;
using mhxy.Client;
using mhxy.Client.Debuger;
using mhxy.Client.OpenTk;
using mhxy.Job;
using mhxy.Logging;
using mhxy.NetEase;
using mhxy.NetEase.Configs;
using mhxy.NetEase.Maps;
using mhxy.NetEase.Profiles;
using mhxy.NetEase.Wass;

#endregion

namespace mhxy {

    /// <summary>
    ///     简单的服务定位器
    /// </summary>
    public static class ServiceLocator {

        /// <summary>
        ///     简单的服务定位器
        /// </summary>
        static ServiceLocator() {
            // 添加全局日志
            LogManager.AddLoggerAdapter(new Log4NetLoggerAdapter());
            GlobalLogger = LogManager.GetLogger(typeof(ServiceLocator));
            try {
                // 添加服务 需要注意服务的依赖顺序
                DebuggerContainer = new DebuggerContainer();
                ScheduleService = new ScheduleService();
                ProfileService = new ProfileService(Global.ProfilePath);
                ConfigManager = new ConfigManager(Global.ConfigPath);
                MapManager = new MapManager(Global.MapPath);
                WasManager = new WasManager(Global.WdfPath);
                DrawingService = new DrawingService();
                ClientEngine = new ClientEngine();
                Window = new GlWindow();
            } catch (Exception e) {
                GlobalLogger.Error(e);
                MessageBox.Show(Resources.ServiceLocator_Load_Error);
                Environment.Exit(0);
            }
        }

        /// <summary>
        ///     全局日志功能
        /// </summary>
        public static ILogger GlobalLogger { get; }

        /// <summary>
        ///     地图管理器
        /// </summary>
        public static IMapManager MapManager { get; }

        /// <summary>
        ///     注解配置管理器
        /// </summary>
        public static IConfigManager ConfigManager { get; }

        /// <summary>
        ///     Was管理器
        /// </summary>
        public static IWasManager WasManager { get; }

        /// <summary>
        ///     绘制服务
        /// </summary>
        public static IDrawingService DrawingService { get; }

        /// <summary>
        ///     存档服务
        /// </summary>
        public static IProfileService ProfileService { get; }

        /// <summary>
        ///     客户端引擎
        /// </summary>
        public static IClientEngine ClientEngine { get; }

        /// <summary>
        ///     游戏主窗口
        /// </summary>
        public static GlWindow Window { get; }

        /// <summary>
        ///     调度服务
        /// </summary>
        public static IScheduleService ScheduleService { get; }

        /// <summary>
        ///     调试器
        /// </summary>
        public static DebuggerContainer DebuggerContainer { get; }

    }

}