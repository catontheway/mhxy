// FileName:  WdfManager.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 08:53
// Description:   

#region

using mhxy.Common;

#endregion

namespace mhxy.Resource.Wdfs {

    /// <summary>
    ///     Wdf 资源管理器
    /// </summary>
    public class WdfManager : ServiceBase, IWdfManager {

        /// <summary>
        ///     Wdf 资源管理器
        /// </summary>
        /// <param name="wdfPath">WDF文件夹</param>
        public WdfManager(string wdfPath) {
            _wdfPath = wdfPath;
        }

        private string _wdfPath;

    }

}