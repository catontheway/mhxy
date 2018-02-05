// FileName:  Tuple3.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180205 14:10
// Description:   

namespace mhxy.Common.Model {

    /// <summary>
    /// int 三元组
    /// </summary>
    public class Tuple3 {

        /// <summary>
        /// 当前值（血量）
        /// </summary>
        public int Current { get; set; }

        /// <summary>
        /// 当前最大值（最高血量-伤势）
        /// </summary>
        public int Max { get; set; }

        /// <summary>
        /// 总共有多少（最高血量）
        /// </summary>
        public int Total { get; set; }

    }

}