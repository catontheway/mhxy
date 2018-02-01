// FileName:  IProfileService.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180201 11:17
// Description:   

using mhxy.Common;
using mhxy.Resource.Profiles;

namespace mhxy.Resource {


    /// <summary>
    /// 存档服务
    /// </summary>
    public interface IProfileService : IService {

        /// <summary>
        /// 是否有
        /// </summary>
        /// <param name="name"></param>
        /// <returns></returns>
        bool Has(string name);

        /// <summary>
        /// 读取
        /// </summary>
        /// <param name="name"></param>
        /// <returns></returns>
        string Read(string name);

        /// <summary>
        /// 创建
        /// </summary>
        /// <param name="name"></param>
        /// <param name="content"></param>
        /// <returns></returns>
        bool Create(string name, string content);

        /// <summary>
        /// 获取存档简介
        /// </summary>
        /// <param name="name"></param>
        /// <returns></returns>
        ProfileBreif GetProfileBreif(string name);

        /// <summary>
        /// 读取Profile
        /// </summary>
        /// <param name="name">名称</param>
        /// <param name="pwd">密码</param>
        /// <param name="id">id</param>
        /// <param name="profile">读取到的存档</param>
        /// <returns></returns>
        bool TryReadProfile(string name, string pwd, int id, out Profile profile);

        /// <summary>
        /// 保存Profile
        /// </summary>
        /// <param name="name">名称</param>
        /// <param name="pwd">密码</param>
        /// <param name="id">id</param>
        /// <param name="profile">存档</param>
        /// <returns></returns>
        bool SaveProfile(string name, string pwd, int id, Profile profile);

        /// <summary>
        /// 删除
        /// </summary>
        /// <param name="name"></param>
        /// <param name="id"></param>
        /// <returns></returns>
        bool DeleteProfile(string name, int id);

    }

}