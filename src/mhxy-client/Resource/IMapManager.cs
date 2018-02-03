// FileName:  IMapManager.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 08:53
// Description:   

#region

using mhxy.Common;
using mhxy.Resource.Maps;

#endregion

namespace mhxy.Resource {

    /// <summary>
    ///     Map 资源管理器
    /// </summary>
    public interface IMapManager : IService {

        /// <summary>
        ///     获取地图对象
        /// </summary>
        /// <param name="mapId">地图Id</param>
        /// <param name="map"></param>
        /// <returns>是否获取成功</returns>
        bool TryGetMap(string mapId, out Map map);

        /// <summary>
        /// 解析并保存所有地图
        /// </summary>
        /// <returns></returns>
        void ParseAllMaps();

    }

}