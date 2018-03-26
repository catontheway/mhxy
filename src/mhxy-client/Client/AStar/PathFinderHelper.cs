// FileName:  PathFinderHelper.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180211 12:49
// Description:   

#region

using System.Collections.Generic;
using System.Drawing;
using mhxy.Common.Model;
using mhxy.NetEase.Maps;

#endregion

namespace mhxy.Client.AStar {

    /// <summary>
    ///     路径帮助类
    /// </summary>
    public class PathFinderHelper {

        private string _currentMapId;

        private Map _currentMap;

        /// <summary>
        /// </summary>
        /// <param name="mapId"></param>
        /// <param name="pointStart"></param>
        /// <param name="pointEnd"></param>
        /// <returns></returns>
        public List<PathNode> FindPath(string mapId, Point pointStart, Point pointEnd) {
            ServiceLocator.GlobalLogger.Info(
                $"Find Path(Point) ：{pointStart.X} {pointStart.Y} to {pointEnd.X} {pointEnd.Y}");
            List<PathNode> result = new List<PathNode>();
            if (!string.Equals(mapId, _currentMapId)) {
                ServiceLocator.MapManager.TryGetMap(mapId, out _currentMap);
                _currentMapId = mapId;
            }

            //转换成cell 坐标
            int startX = pointStart.X / Global.PixelPerCell;
            int startY = pointStart.Y / Global.PixelPerCell;
            int endX = pointEnd.X / Global.PixelPerCell;
            int endY = pointEnd.Y / Global.PixelPerCell;
            var pathFinder = new AStarFinder(_currentMap.Grid);
            //寻路
            var way = pathFinder.FindPath(new Point(startX, startY), new Point(endX, endY));
            if (way != null && way.Count != 0) {
                way.Reverse();
                PathNode pre = new PathNode {Point = pointStart};
                foreach (var wayNode in way) {
                    var current = new PathNode {
                        Point = new Point(wayNode.X * Global.PixelPerCell + Global.PixelPerCell / 2,
                            wayNode.Y * Global.PixelPerCell + Global.PixelPerCell / 2)
                    };
                    var mid = new PathNode {
                        Point = new Point((pre.Point.X + current.Point.X) / 2, (pre.Point.Y + current.Point.Y) / 2)
                    };
                    pre.Direction = CalcDirection(pre, current);
                    mid.Direction = pre.Direction;
                    current.Direction = pre.Direction;
                    result.Add(mid);
                    result.Add(current);
                    pre = current;
                }
            }

            return result;
        }

        /// <summary>
        ///     计算两个点之间的方向
        /// </summary>
        /// <param name="pre"></param>
        /// <param name="current"></param>
        /// <returns></returns>
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