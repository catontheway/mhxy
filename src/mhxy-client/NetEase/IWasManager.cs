// FileName:  IWasManager.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 08:53
// Description:   

#region

#endregion

#region

using mhxy.NetEase.Wass;

#endregion

namespace mhxy.NetEase {

    /// <summary>
    ///     Was 资源管理器
    /// </summary>
    public interface IWasManager : IResourceManager {

        /// <summary>
        ///     获取一个Was数据
        /// </summary>
        /// <param name="fileId">文件Id</param>
        /// <param name="wasId">was UID</param>
        /// <param name="wds">获取到的数据</param>
        /// <returns>是否获取成功</returns>
        bool TryGetSpWas(string fileId, int wasId, out SpWas wds);

    }

}