// FileName:  ServiceBase.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 08:53
// Description:   

#region

using mhxy.Logging;

#endregion

namespace mhxy.Common {

    /// <summary>
    ///     Service 基类
    /// </summary>
    public abstract class ServiceBase : IService {

        /// <summary>
        /// </summary>
        protected ServiceBase() {
            Logger = LogManager.GetLogger(this);
        }

        /// <summary>
        ///     默认 Logger
        /// </summary>
        protected ILogger Logger { get; }

    }

}