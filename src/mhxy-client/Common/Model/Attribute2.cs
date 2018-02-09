// FileName:  Attribute2.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180205 14:01
// Description:   

namespace mhxy.Common.Model {

    /// <summary>
    ///     属性(气血 魔法)
    /// </summary>
    public class Attribute2 {

        /// <summary>
        ///     气血
        /// </summary>
        public Tuple3 Blood { get; set; }

        /// <summary>
        ///     命中
        /// </summary>
        public int Hit { get; set; }

        /// <summary>
        ///     伤害
        /// </summary>
        public int Harm { get; set; }

    }

}