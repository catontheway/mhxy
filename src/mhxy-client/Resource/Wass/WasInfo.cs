// FileName:  WasFile.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180206 15:36
// Description:   

namespace mhxy.Resource.Wass {

    /// <summary>
    /// 文件列表节点
    /// </summary>
    public class WasInfo {

        /// <summary>
        /// 
        /// </summary>
        public WasInfo(int uid,   int offset, int size, int space) {
            Uid = uid;
            Offset = offset;
            Size = size;
            Space = space;
        }

        /// <summary>
        /// 文件内部ID
        /// </summary>
        public int Uid { get; }

        /// <summary>
        /// 文件大小
        /// </summary>
        public int Size { get; }

        /// <summary>
        /// 偏移量
        /// </summary>
        public int Offset { get; }

        /// <summary>
        /// 文件剩余空间
        /// </summary>
        public int Space { get; }

    }

}