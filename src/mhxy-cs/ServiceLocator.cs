using mhxy.Display;
using mhxy.Engine;
using mhxy.Resource;
using mhxy.Resource.Configs;
using mhxy.Resource.Maps;
using mhxy.Resource.Profile;
using mhxy.Resource.Wdfs;

namespace mhxy {

    /// <summary>
    /// 简单的服务定位器
    /// </summary>
    public static class ServiceLocator {

        /// <summary>
        /// 
        /// </summary>
        static ServiceLocator() {
            ConfigManager = new ConfigManager(Environment.ConfigPath);
            ProfileService = new ProfileService(Environment.ProfilePath);
            MapManager = new MapManager(Environment.MapPath);
            WdfManager = new WdfManager(Environment.WdfPath);
            WasManager = new WasManager();
            DrawingService = new DrawingService();
            ClientEngine = new ClientEngine();
        }

        /// <summary>
        /// 地图管理器
        /// </summary>
        public static IMapManager MapManager { get; }

        /// <summary>
        /// WDF管理器
        /// </summary>
        public static IWdfManager WdfManager { get; }

        /// <summary>
        /// 注解配置管理器
        /// </summary>
        public static IConfigManager ConfigManager { get; }

        /// <summary>
        /// Was管理器
        /// </summary>
        public static IWasManager WasManager { get; }

        /// <summary>
        /// 绘制服务
        /// </summary>
        public static IDrawingService DrawingService { get; }

        /// <summary>
        /// 存档服务
        /// </summary>
        public static IProfileService ProfileService { get; }

        /// <summary>
        /// 客户端引擎
        /// </summary>
        public static IClientEngine ClientEngine { get; }

    }

}