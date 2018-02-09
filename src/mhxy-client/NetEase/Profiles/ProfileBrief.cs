// FileName:  ProfileBrief.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 08:53
// Description:   

#region

using mhxy.Common.Model;

#endregion

namespace mhxy.NetEase.Profiles {

    /// <summary>
    ///     存档简介
    /// </summary>
    public class ProfileBrief {

        /// <summary>
        ///     编号
        /// </summary>
        public int Id { get; set; }

        /// <summary>
        ///     角色名称
        /// </summary>
        public string Name { get; set; }

        /// <summary>
        ///     等级
        /// </summary>
        public int Level { get; set; }

        /// <summary>
        ///     角色类型
        /// </summary>
        public RoleType Role { get; set; }

    }

}