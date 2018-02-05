// FileName:  ProfileService.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 08:53
// Description:   

#region

using System;
using System.IO;
using System.Linq;
using mhxy.Common;
using mhxy.Utils;

#endregion

namespace mhxy.Resource.Profiles {

    /// <summary>
    ///     存档服务
    /// </summary>
    public class ProfileService : ServiceBase, IProfileService {

        /// <summary>
        /// </summary>
        /// <param name="profilePath"></param>
        public ProfileService(string profilePath) {
            _profilePath = profilePath;
        }

        /// <summary>
        ///     存档文件夹
        /// </summary>
        private readonly string _profilePath;

        /// <summary>
        ///     是否有
        /// </summary>
        /// <param name="name"></param>
        /// <returns></returns>
        public bool Has(string name) {
            Logger.Info($"Has : {name}");
            try {
                return File.Exists(Path.Combine(_profilePath, name));
            } catch (Exception e) {
                Logger.Error($"Has {name}", e);
                return false;
            }
        }

        /// <summary>
        ///     读取
        /// </summary>
        /// <param name="name"></param>
        /// <returns></returns>
        public string Read(string name) {
            Logger.Info($"Read : {name}");
            try {
                return File.ReadAllText(Path.Combine(_profilePath, name));
            } catch (Exception e) {
                Logger.Error($"Read : {name}", e);
                return string.Empty;
            }
        }

        /// <summary>
        ///     写入
        /// </summary>
        /// <param name="name"></param>
        /// <param name="content"></param>
        /// <returns></returns>
        public bool Create(string name, string content) {
            Logger.Info($"Create : {name} {content}");
            try {
                File.WriteAllText(Path.Combine(_profilePath, name), content);
                return true;
            } catch (Exception e) {
                Logger.Error($"Save {name}", e);
            }

            return false;
        }

        /// <summary>
        ///     获取存档简介
        /// </summary>
        /// <param name="name"></param>
        /// <returns></returns>
        public ProfileList GetProfileList(string name) {
            Logger.Info($"GetProfileBreif : {name}");
            ProfileList list = new ProfileList();
            string fileName = Path.Combine(_profilePath, $"{name}.breif");
            try {
                if (File.Exists(fileName)) {
                    var profileStr = File.ReadAllText(fileName);
                    JsonUtil.TryToObject(profileStr, out list);
                } else {
                    SaveProfileList(name, list);
                }
            } catch (Exception e) {
                Logger.Error($"Read Profile {fileName}", e);
            }

            return list;
        }

        /// <summary>
        ///     读取Profile
        /// </summary>
        /// <param name="name">名称</param>
        /// <param name="pwd">密码</param>
        /// <param name="id">id</param>
        /// <param name="profile">读取到的存档</param>
        /// <returns></returns>
        public bool TryReadProfile(string name, string pwd, int id, out Profile profile) {
            Logger.Info($"TryReadProfile : {name} {pwd} {id}");
            profile = null;
            string fileName = Path.Combine(_profilePath, $"{name}.{id}.save");
            try {
                if (!File.Exists(fileName)) {
                    return false;
                }

                var profileStr = File.ReadAllText(fileName);
                if (Global.Encrypt) {
                    profileStr = profileStr.AesDecrypt(name, pwd);
                }

                return JsonUtil.TryToObject(profileStr, out profile);
            } catch (Exception e) {
                Logger.Error($"Read Profile {fileName}", e);
            }

            return false;
        }

        /// <summary>
        ///     保存Profile
        /// </summary>
        /// <param name="name">名称</param>
        /// <param name="pwd">密码</param>
        /// <param name="id">id</param>
        /// <param name="profile">存档</param>
        /// <returns></returns>
        public bool SaveProfile(string name, string pwd, int id, Profile profile) {
            Logger.Info($"SaveProfile : {name} {pwd} {id}");
            string fileName = Path.Combine(_profilePath, $"{name}.{id}.save");
            if (JsonUtil.TryToJson(profile, out string profileStr)) {
                Logger.Debug($"SaveProfile : {name} \n {profileStr}");
                try {
                    if (Global.Encrypt) {
                        profileStr = profileStr.AesEncrypt(name, pwd);
                    }

                    File.WriteAllText(fileName, profileStr);
                    // 更新Brief
                    var profileList = GetProfileList(name);
                    var breif = profileList.ProfileBreifs.FirstOrDefault(source => source.Id == id);
                    if (breif == null) {
                        breif = new ProfileBrief();
                        profileList.ProfileBreifs.Add(breif);
                    }

                    breif.Id = id;
                    breif.Name = profile.Name;
                    breif.Role = profile.Role;
                    breif.Level = profile.Level;
                    SaveProfileList(name, profileList);
                    return true;
                } catch (Exception e) {
                    Logger.Error($"Save Profile {fileName}", e);
                }
            }

            return false;
        }

        /// <summary>
        ///     删除
        /// </summary>
        /// <param name="name"></param>
        /// <param name="id"></param>
        /// <returns></returns>
        public bool DeleteProfile(string name, int id) {
            Logger.Info($"DeleteProfile : {name} {id}");
            string fileName = Path.Combine(_profilePath, $"{name}.{id}.save");
            if (!File.Exists(fileName)) {
                return false;
            }

            File.Delete(fileName);
            var profileList = GetProfileList(name);
            var breif = profileList.ProfileBreifs.FirstOrDefault(source => source.Id == id);
            if (breif != null) {
                profileList.ProfileBreifs.Remove(breif);
                SaveProfileList(name, profileList);
            }

            // 更新Brief
            return true;
        }

        /// <summary>
        /// </summary>
        /// <param name="name"></param>
        /// <param name="list"></param>
        private void SaveProfileList(string name, ProfileList list) {
            string fileName = Path.Combine(_profilePath, $"{name}.breif");
            try {
                JsonUtil.TryToJson(list, out string listStr);
                File.WriteAllText(fileName, listStr);
            } catch (Exception e) {
                Logger.Error($"SaveProfileList {name}", e);
            }
        }

    }

}