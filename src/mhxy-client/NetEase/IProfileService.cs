// FileName:  IProfileService.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 08:53
// Description:   

#region

using mhxy.Common;
using mhxy.NetEase.Profiles;

#endregion

namespace mhxy.NetEase {

    /// <summary>
    ///     存档服务
    /// </summary>
    public interface IProfileService : IService {

        /// <summary>
        ///     是否有用户
        /// </summary>
        /// <param name="name">用户名</param>
        /// <returns></returns>
        bool Has(string name);

        /// <summary>
        ///     读取用户
        /// </summary>
        /// <param name="name">用户名</param>
        /// <param name="content"></param>
        /// <returns></returns>
        bool TryRead(string name, out string content);

        /// <summary>
        ///     创建用户
        /// </summary>
        /// <param name="name">用户名</param>
        /// <param name="content"></param>
        /// <returns></returns>
        bool TryCreate(string name, string content);

        /// <summary>
        ///     获取存档简介
        /// </summary>
        /// <param name="name">用户名</param>
        /// <returns></returns>
        ProfileList GetProfileList(string name);

        /// <summary>
        ///     读取Profile
        /// </summary>
        /// <param name="name">用户名</param>
        /// <param name="pwd">密码</param>
        /// <param name="id">存档id</param>
        /// <param name="profile">读取到的存档</param>
        /// <returns></returns>
        bool TryReadProfile(string name, string pwd, int id, out Profile profile);

        /// <summary>
        ///     保存Profile
        /// </summary>
        /// <param name="name">用户名</param>
        /// <param name="pwd">密码</param>
        /// <param name="id">存档id</param>
        /// <param name="profile">存档</param>
        /// <returns></returns>
        bool TrySaveProfile(string name, string pwd, int id, Profile profile);

        /// <summary>
        ///     删除Profile
        /// </summary>
        /// <param name="name">用户名</param>
        /// <param name="id">存档id</param>
        /// <returns></returns>
        bool TryDeleteProfile(string name, int id);

    }

}