namespace mhxy.Resource.Maps {

    /// <summary>
    ///     Unit 数据
    /// </summary>
    public class UnitData {

        /// <summary>
        ///     Unit 数据
        /// </summary>
        /// <param name="flag">标志位</param>
        /// <param name="size">大小</param>
        public UnitData(string flag, int size) {
            Flag = flag;
            Size = size;
            Data = new byte[Size];
        }

        /// <summary>
        ///     标志位
        /// </summary>
        public string Flag { get; set; }

        /// <summary>
        ///     大小
        /// </summary>
        public int Size { get; set; }

        /// <summary>
        ///     数据
        /// </summary>
        public byte[] Data { get; set; }

    }

}