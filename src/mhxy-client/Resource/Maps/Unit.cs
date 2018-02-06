// FileName:  Unit.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 08:53
// Description:   

namespace mhxy.Resource.Maps {

    /// <summary>
    ///     Unit 对象
    /// </summary>
    public class Unit {

        /// <summary>
        ///     Unit 对象
        /// </summary>
        public Unit(uint begin, UnitData img, UnitData cell, UnitData brig) {
            Begin = begin;
            Image = img;
            Cell = cell;
            Brig = brig;
        }

        /// <summary>
        ///     开始位置
        /// </summary>
        public uint Begin { get; }

        /// <summary>
        ///     Img 数据
        /// </summary>
        public UnitData Image { get; }

        /// <summary>
        ///     Cell 数据
        /// </summary>
        public UnitData Cell { get; set; }

        /// <summary>
        ///     Brig 数据
        /// </summary>
        public UnitData Brig { get; set; }

        /// <summary>
        /// </summary>
        public bool Decoded { get; set; }

        /// <summary>
        /// 真实的Image数据
        /// </summary>
        public byte[] RealImage { get; set; }

    }

}