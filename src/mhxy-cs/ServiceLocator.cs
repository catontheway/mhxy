using mhxy.Core;
using mhxy.Core.Configs;
using mhxy.Core.Maps;
using mhxy.Core.Wdfs;

namespace mhxy {

    /// <summary>
    /// 简单的服务定位器
    /// </summary>
    public static class ServiceLocator {

        
        static ServiceLocator() {
            MapManager = new MapManager(Environment.MapPath);
            WdfManager = new WdfManager(Environment.WdfPath);
            ConfigManager = new ConfigManager(Environment.ConfigPath);
            WasManager = new WasManager(WdfManager, ConfigManager);
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

    }

}