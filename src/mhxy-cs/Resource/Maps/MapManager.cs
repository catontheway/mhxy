using System;
using System.IO;
using mhxy.Common;
using mhxy.Extensions;
using mhxy.Logging;

namespace mhxy.Resource.Maps {


    /// <summary>
    /// Map 资源管理器
    /// </summary>
    public class MapManager : ServiceBase, IMapManager {

        /// <summary>
        /// Map 资源管理器
        /// </summary>
        /// <param name="mapPath">地图文件夹</param>
        public MapManager(string mapPath) {
            _logger = LogManager.GetLogger(this);
            _mapPath = mapPath;
            _logger.Debug($"Create MapManager : {mapPath}");
        }

        /// <summary>
        /// 地图文件夹
        /// </summary>
        private readonly string _mapPath;

        /// <summary>
        /// 日志
        /// </summary>
        private readonly ILogger _logger;

        /// <summary>
        /// 获取地图对象
        /// </summary>
        /// <param name="mapId">地图Id</param>
        /// <param name="map"></param>
        /// <returns>是否获取成功</returns>
        public bool TryGetMap(string mapId, out Map map) {
            try {
                mapId.CheckNotNullOrEmpty("mapId");
                var mapFileName = Path.Combine(_mapPath, $"{mapId}.map");
                map = new Map(mapFileName);
                map.Load();
                return true;
            } catch (Exception e) {
                _logger.Error($"Error In Get Map:{mapId}", e);
                map = null;
                return false;
            }
        }
    }

}