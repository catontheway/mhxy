namespace mhxy.Resource.Configs {

    /// <summary>
    /// 配置管理器
    /// </summary>
    public class ConfigManager : IConfigManager {

        /// <summary>
        /// 配置管理器
        /// </summary>
        public ConfigManager(string configPath) {
            _configPath = configPath;
        }

        private string _configPath;


    }

}