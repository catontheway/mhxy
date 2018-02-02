// FileName:  Wdf.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 08:53
// Description:   

namespace mhxy.Resource.Wdfs {

    /// <summary>
    ///     WDF文件对象
    /// </summary>
    public class Wdf : ResourceBase {

        /// <summary>
        ///     WDF文件对象
        /// </summary>
        /// <param name="fileName">文件名</param>
        public Wdf(string fileName) {
            _fileName = fileName;
        }

        private string _fileName;

    }

}