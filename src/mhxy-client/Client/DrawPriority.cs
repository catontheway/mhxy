// FileName:  DrawPriority.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180205 13:58
// Description:   

namespace mhxy.Client {

    /// <summary>
    ///     绘制图层级别
    /// </summary>
    public enum DrawPriority {

        /// <summary>
        ///     最底层(例如,场景图)
        /// </summary>
        Lowest = 1,

        /// <summary>
        ///     稍底层(例如,Player)
        /// </summary>
        Lower = 2,

        /// <summary>
        ///     正常层(地图蒙版)
        /// </summary>
        Normal = 3,

        /// <summary>
        ///     稍高层(例如,系统界面 属性 物品 任务 小地图等普通窗口)
        /// </summary>
        Higher = 4,

        /// <summary>
        ///     最高层(消息)
        /// </summary>
        Highest = 5

    }

}