namespace mhxy.Core.Wdfs {


    /// <summary>
    /// Wdf 资源管理器
    /// </summary>
    public class WdfManager: IWdfManager {

        /// <summary>
        /// Wdf 资源管理器
        /// </summary>
        /// <param name="wdfPath">WDF文件夹</param>
        public WdfManager(string wdfPath) {
            _wdfPath = wdfPath;
        }

        private string _wdfPath;
    }

}