// FileName:  PathFinderHelper.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180211 12:49
// Description:   

using System.Collections.Generic;
using System.Drawing;
using mhxy.Common.Model;
using mhxy.NetEase.Maps;

namespace mhxy.Client.AStar {

    /// <summary>
    /// 路径帮助类
    /// </summary>
    public class PathFinderHelper {

        private string _currentMapId;

        private Map _currentMap;

        /// <summary>
        /// 
        /// </summary>
        /// <param name="mapId"></param>
        /// <param name="pointStart"></param>
        /// <param name="pointEnd"></param>
        /// <returns></returns>
        public List<PathNode> FindPath(string mapId, Point pointStart, Point pointEnd) {
            ServiceLocator.GlobalLogger.Info($"FindPath {pointStart.X} {pointStart.Y} to {pointEnd.X} {pointEnd.Y}");
            List<PathNode> result = new List<PathNode>();
            if (!string.Equals(mapId, _currentMapId)) {
                ServiceLocator.MapManager.TryGetMap(mapId, out _currentMap);
                _currentMapId = mapId;
            }
            int startY = pointStart.X / Global.PixelPerCell;
            int startX = pointStart.Y / Global.PixelPerCell;
            int endY = pointEnd.X / Global.PixelPerCell;
            int endX = pointEnd.Y / Global.PixelPerCell;
            var pathFinder = new AStarFinder(_currentMap.Grid);
            var way = pathFinder.FindPath(new Point(startX, startY), new Point(endX, endY));
            if (way != null && way.Count != 0) {
                way.Reverse();
                PathNode pre = new PathNode { Point = pointStart };
                foreach (var wayNode in way) {
                    var current = new PathNode {
                        Point = new Point(wayNode.Y * Global.PixelPerCell, wayNode.X * Global.PixelPerCell)
                    };
                    result.Add(current);
                    pre.Direction = CalcDirection(pre, current);
                    pre = current;
                }
                // result.Add(new PathNode { Point = pointEnd, Direction = pre.Direction });
            }
            return result;
        }

        private Direction CalcDirection(PathNode pre, PathNode current) {
            var distX = current.Point.X - pre.Point.X;
            var distY = current.Point.Y - pre.Point.Y;
            if (distX == 0) {
                return distY > 0 ? Direction.Down : Direction.Up;
            }

            if (distY == 0) {
                return distX > 0 ? Direction.Right : Direction.Left;
            }

            if (distX < 0) {
                return distY > 0 ? Direction.LeftDown : Direction.LeftUp;
            }
            return distY > 0 ? Direction.RightDown : Direction.RightUp;
        }
    }

}