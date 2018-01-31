namespace mhxy.Core.Configs {

    /// <summary>
    /// 注解配置管理器
    /// </summary>
    public class ConfigManager : IConfigManager {

        /// <summary>
        /// 注解配置管理器
        /// </summary>
        public ConfigManager(string configPath) {
            _configPath = configPath;
        }

        private string _configPath;


    }

}