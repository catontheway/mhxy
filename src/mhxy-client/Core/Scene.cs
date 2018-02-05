// FileName:  Scene.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 08:53
// Description:   

namespace mhxy.Core {

    /// <summary>
    ///     场景
    /// </summary>
    public class Scene {

        /// <summary>
        /// 显示的地图
        /// </summary>
        public string MapId { get; set; }

        /// <summary>
        /// 主角所在地图的位置
        /// </summary>
        public int PlayerX { get; set; }

        /// <summary>
        /// 主角所在地图的位置
        /// </summary>
        public int PlayerY { get; set; }

    }

}