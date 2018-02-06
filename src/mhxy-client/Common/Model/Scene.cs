// FileName:  Scene.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180205 13:56
// Description:   

#region

using System.Drawing;

#endregion

namespace mhxy.Common.Model {

    /// <summary>
    ///     场景
    /// </summary>
    public class Scene {

        /// <summary>
        ///     显示的地图
        /// </summary>
        public string MapId { get; set; }

        /// <summary>
        ///     主角所在位置
        /// </summary>
        public Point PlayerAt { get; set; }

    }

}