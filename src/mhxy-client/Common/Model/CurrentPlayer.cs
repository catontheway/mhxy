// FileName:  CurrentPlayer.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180205 13:56
// Description:   

#region

using System.Drawing;

#endregion

namespace mhxy.Common.Model {

    /// <summary>
    ///     主角
    /// </summary>
    public class CurrentPlayer : Player {

        /// <summary>
        /// </summary>
        public static CurrentPlayer None = new CurrentPlayer();

        /// <summary>
        ///     主角所在位置
        /// </summary>
        public Point At { get; set; }

        /// <summary>
        ///     朝向
        /// </summary>
        public Direction FaceTo { get; set; }

        /// <summary>
        ///     角色类型
        /// </summary>
        public RoleType Role { get; set; }

        /// <summary>
        ///     等级
        /// </summary>
        public int Level { get; set; }

        /// <summary>
        ///     名字
        /// </summary>
        public string Name { get; set; }

        /// <summary>
        ///     是否正在移动
        /// </summary>
        public bool Moving { get; set; }

    }

}