// FileName:  ConfigManager.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 08:53
// Description:   

namespace mhxy.NetEase.Configs {

    /// <summary>
    ///     配置管理器
    /// </summary>
    public class ConfigManager : IConfigManager {

        /// <summary>
        ///     配置管理器
        /// </summary>
        public ConfigManager(string configPath) {
            _configPath = configPath;
        }

        private string _configPath;

    }

}