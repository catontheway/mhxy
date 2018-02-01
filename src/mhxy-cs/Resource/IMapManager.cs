using mhxy.Common;
using mhxy.Resource.Maps;

namespace mhxy.Resource {

    /// <summary>
    /// Map 资源管理器
    /// </summary>
    public interface IMapManager : IService {

        /// <summary>
        /// 获取地图对象
        /// </summary>
        /// <param name="mapId">地图Id</param>
        /// <param name="map"></param>
        /// <returns>是否获取成功</returns>
        bool TryGetMap(string mapId,out Map map);

    }

}