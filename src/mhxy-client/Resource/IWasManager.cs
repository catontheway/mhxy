// FileName:  IWasManager.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 08:53
// Description:   

#region

#endregion

#region

using mhxy.Resource.Wass;

#endregion

namespace mhxy.Resource {

    /// <summary>
    ///     Was 资源管理器
    /// </summary>
    public interface IWasManager : IResourceManager {

        /// <summary>
        /// </summary>
        /// <param name="fileId"></param>
        /// <param name="wasId"></param>
        /// <param name="wds"></param>
        /// <returns></returns>
        bool TryGetSpWas(string fileId, int wasId, out SpWas wds);

    }

}