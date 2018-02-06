// FileName:  CurrentPlayer.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180205 13:56
// Description:   

#region

using System.Drawing;

#endregion

namespace mhxy.Common.Model {

    /// <summary>
    /// </summary>
    public class CurrentPlayer : Player {

        /// <summary>
        /// </summary>
        public static CurrentPlayer None = new CurrentPlayer();

        /// <summary>
        ///     主角所在位置
        /// </summary>
        public Point At { get; set; }

    }

}