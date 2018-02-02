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
        public Unit(uint begin, UnitData jpeg, UnitData cell, UnitData brig) {
            Begin = begin;
            Jpeg = jpeg;
            Cell = cell;
            Brig = brig;
        }

        /// <summary>
        /// </summary>
        public uint Begin { get; }

        /// <summary>
        ///     Jpeg 数据
        /// </summary>
        public UnitData Jpeg { get; }

        /// <summary>
        ///     Cell 数据
        /// </summary>
        public UnitData Cell { get; set; }

        /// <summary>
        ///     Brig 数据
        /// </summary>
        public UnitData Brig { get; set; }

    }

}