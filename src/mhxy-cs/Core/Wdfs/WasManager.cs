namespace mhxy.Core.Wdfs {

    /// <summary>
    /// Was 资源管理器
    /// </summary>
    public class WasManager : IWasManager {

        /// <summary>
        /// Was 资源管理器
        /// </summary>
        public WasManager(IWdfManager wdfMgr, IConfigManager configMgr) {
            _wdfMgr = wdfMgr;
            _configMgr = configMgr;
        }

        private IWdfManager _wdfMgr;

        private IConfigManager _configMgr;

    }
}