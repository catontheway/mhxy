// FileName:  Profile.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 08:53
// Description:   

#region

using mhxy.Common.Model;

#endregion

namespace mhxy.Resource.Profiles {

    /// <summary>
    ///     存档
    /// </summary>
    public class Profile {

        /// <summary>
        ///     默认构造Profile
        /// </summary>
        public Profile() : this(RoleType.剑侠客.ToString(), RoleType.剑侠客, "1001", 100, 100) {
        }

        /// <summary>
        ///     构造Profile
        /// </summary>
        /// <param name="name"></param>
        /// <param name="type"></param>
        /// <param name="mapId"></param>
        /// <param name="playerX"></param>
        /// <param name="playerY"></param>
        public Profile(string name, RoleType type, string mapId, int playerX, int playerY) {
            Level = 0;
            Role = type;
            Name = name;
            MapId = mapId;
            PlayerX = playerX;
            PlayerY = playerY;
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

        /// <summary>
        /// 
        /// </summary>
        public string MapId { get; set; }

        /// <summary>
        /// 主角所在位置
        /// </summary>
        public int PlayerX { get; set; }

        /// <summary>
        /// 主角所在位置
        /// </summary>
        public int PlayerY { get; set; }

    }

}