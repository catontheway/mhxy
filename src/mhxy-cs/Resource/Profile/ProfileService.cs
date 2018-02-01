// FileName:  ProfileService.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180201 11:17
// Description:   

using mhxy.Common;
using mhxy.Logging;

namespace mhxy.Resource.Profile {

    /// <summary>
    /// 存档服务
    /// </summary>
    public class ProfileService : ServiceBase, IProfileService {

        /// <summary>
        /// 
        /// </summary>
        /// <param name="profilePath"></param>
        public ProfileService(string profilePath) {
            _logger = LogManager.GetLogger(this);
            _profilePath = profilePath;
        }

        /// <summary>
        /// 日志
        /// </summary>
        private readonly ILogger _logger;

        /// <summary>
        /// 存档文件夹
        /// </summary>
        private readonly string _profilePath;

    }

}