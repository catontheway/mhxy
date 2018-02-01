// FileName:  ProfileService.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180201 11:17
// Description:   

using System;
using System.IO;
using mhxy.Common;
using mhxy.Logging;
using mhxy.Utils;

namespace mhxy.Resource.Profiles {

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

        /// <summary>
        /// 是否有
        /// </summary>
        /// <param name="name"></param>
        /// <returns></returns>
        public bool Has(string name) {
            try {
                return File.Exists(Path.Combine(_profilePath, name));
            } catch (Exception e) {
                _logger.Error($"Has {name}", e);
                return false;
            }
        }

        /// <summary>
        /// 读取
        /// </summary>
        /// <param name="name"></param>
        /// <returns></returns>
        public string Read(string name) {
            try {
                return File.ReadAllText(Path.Combine(_profilePath, name));
            } catch (Exception e) {
                _logger.Error($"Read {name}", e);
                return string.Empty;
            }
        }

        /// <summary>
        /// 写入
        /// </summary>
        /// <param name="name"></param>
        /// <param name="content"></param>
        /// <returns></returns>
        public bool Create(string name, string content) {
            try {
                File.WriteAllText(Path.Combine(_profilePath, name), content);
                return true;
            } catch (Exception e) {
                _logger.Error($"Save {name}", e);
            }
            return false;
        }

        /// <summary>
        /// 获取存档简介
        /// </summary>
        /// <param name="name"></param>
        /// <returns></returns>
        public ProfileBreif GetProfileBreif(string name) {
            string fileName = Path.Combine(_profilePath, $"{name}.breif");
            try {
                if (File.Exists(fileName)) {
                    var profileStr = File.ReadAllText(fileName);
                    JsonUtil.TryToObject(profileStr, out ProfileBreif _);
                }
            } catch (Exception e) {
                _logger.Error($"Read Profile {fileName}", e);
            }
            return new ProfileBreif();
        }

        /// <summary>
        /// 读取Profile
        /// </summary>
        /// <param name="name">名称</param>
        /// <param name="pwd">密码</param>
        /// <param name="id">id</param>
        /// <param name="profile">读取到的存档</param>
        /// <returns></returns>
        public bool TryReadProfile(string name, string pwd, int id, out Profile profile) {
            profile = null;
            string fileName = Path.Combine(_profilePath, $"{name}.{id}.save");
            try {
                if (!File.Exists(fileName)) {
                    return false;
                }
                var profileStr = File.ReadAllText(fileName);
                if (Environment.Encrypt) {
                    profileStr = profileStr.AesDecrypt(name, pwd);
                }
                return JsonUtil.TryToObject(profileStr, out profile);
            } catch (Exception e) {
                _logger.Error($"Read Profile {fileName}", e);
            }
            return false;
        }

        /// <summary>
        /// 保存Profile
        /// </summary>
        /// <param name="name">名称</param>
        /// <param name="pwd">密码</param>
        /// <param name="id">id</param>
        /// <param name="profile">存档</param>
        /// <returns></returns>
        public bool SaveProfile(string name, string pwd, int id, Profile profile) {
            string fileName = Path.Combine(_profilePath, $"{name}.{id}.save");
            if (JsonUtil.TryToJson(profile, out string profileStr)) {
                try {
                    if (Environment.Encrypt) {
                        profileStr = profileStr.AesEncrypt(name, pwd);
                    }
                    File.WriteAllText(fileName, profileStr);
                    // 更新Brief
                    return true;
                } catch (Exception e) {
                    _logger.Error($"Save Profile {fileName}", e);
                }
            }
            return false;
        }

        /// <summary>
        /// 删除
        /// </summary>
        /// <param name="name"></param>
        /// <param name="id"></param>
        /// <returns></returns>
        public bool DeleteProfile(string name, int id) {
            // 更新Brief
            return true;
        }

    }

}