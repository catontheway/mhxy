// FileName:  Profile.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 08:53
// Description:   

#region

using mhxy.Core;

#endregion

namespace mhxy.Resource.Profiles {

    /// <summary>
    ///     存档
    /// </summary>
    public class Profile {

        /// <summary>
        ///     默认构造Profile
        /// </summary>
        public Profile() : this(RoleType.剑侠客.ToString(), RoleType.剑侠客) {
        }

        /// <summary>
        ///     构造Profile
        /// </summary>
        /// <param name="name"></param>
        /// <param name="type"></param>
        public Profile(string name, RoleType type) {
            Level = 0;
            Role = type;
            Name = name;
        }

        /// <summary>
        ///     初始创建
        /// </summary>
        public bool InitCreate { get; set; }

        /// <summary>
        ///     角色名称
        /// </summary>
        public string Name { get; set; }

        /// <summary>
        ///     等级
        /// </summary>
        public int Level { get; set; }

        /// <summary>
        /// </summary>
        public RoleType Role { get; set; }

    }

}