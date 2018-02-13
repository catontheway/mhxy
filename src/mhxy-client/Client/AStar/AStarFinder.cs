// FileName:  AStarFinder.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180211 15:53
// Description:   

#region

using System.Collections.Generic;
using System.Drawing;

#endregion

namespace mhxy.Client.AStar {

    /// <summary>
    /// </summary>
    public class AStarFinder {

        /// <summary>
        /// </summary>
        /// <param name="grid">地图</param>
        public AStarFinder(byte[,] grid) {
            _grid = grid;
            _length0 = _grid.GetLength(0);
            _length1 = _grid.GetLength(1);
        }

        private readonly List<AStarPoint> _openList = new List<AStarPoint>();
        private readonly List<AStarPoint> _closeList = new List<AStarPoint>();
        private readonly int _length0;
        private readonly int _length1;
        private readonly byte[,] _grid;

        /// <summary>
        ///     寻路
        /// </summary>
        /// <param name="start">起点</param>
        /// <param name="end">终点</param>
        /// <returns></returns>
        public List<Point> FindPath(Point start, Point end) {
            ServiceLocator.GlobalLogger.Debug($"FindPath(Cell Point) : {start.X} {start.Y} to {end.X} {end.Y}");
            List<Point> way = new List<Point>();
            var index0 = start.Y;
            var index1 = start.X;
            //预判断
            if (index0 < 0 || index0 >= _length0 || index1 < 0 || index1 >= _length1 ||
                _grid[index0, index1] == 0) {
                return way;
            }

            //尝试获取一个可用的终点
            if (!TryGetAnValidEndPoint(end, out end)) {
                return way;
            }

            //将起点加入开放列表
            var startPoint = new AStarPoint(start.X, start.Y, null, end);
            AddToOpenList(startPoint);
            AStarPoint current = startPoint;
            //从开放列表中寻路
            while (!OpenListIsEmpty()) {
                //获取G+H最小的节点
                current = GetMinFFromOpenList();
                if (current.X == end.X && current.Y == end.Y) {
                    break; // Success
                }

                //检查并设置当前周围八个点
                Check8(current, end);
                RemoveFromOpenList(current);
                AddToCloseList(current);
            }

            while (current != null) {
                way.Add(new Point(current.X, current.Y));
                current = current.Parent;
            }

            return way;
        }

        private void Check8(AStarPoint current, Point end) {
            for (int x = current.X - 1; x < current.X + 2; x++) {
                for (int y = current.Y - 1; y < current.Y + 2; y++) {
                    var index0 = y;
                    var index1 = x;
                    //添加条件:
                    //不是当前点
                    //有效点
                    //不在开放列表
                    //不在封闭列表
                    if (x == current.X && y == current.Y
                        || index0 < 0 || index0 >= _length0 || index1 < 0 || index1 >= _length1
                        || _grid[index0, index1] == 0
                        || IsInOpenList(x, y)
                        || IsInCloseList(x, y)) {
                    } else {
                        var point = new AStarPoint(x, y, current, end);
                        AddToOpenList(point);
                    }
                }
            }
        }

        /// <summary>
        /// </summary>
        /// <returns></returns>
        private bool OpenListIsEmpty() {
            return _openList.Count == 0;
        }

        private void AddToOpenList(AStarPoint toAdd) {
            if (!IsInOpenList(toAdd.X, toAdd.Y)) {
                _openList.Add(toAdd);
            }
        }

        private void RemoveFromOpenList(AStarPoint toAdd) {
            _openList.Remove(toAdd);
        }

        private void AddToCloseList(AStarPoint toAdd) {
            if (!IsInCloseList(toAdd.X, toAdd.Y)) {
                _closeList.Add(toAdd);
            }
        }

        //判断关闭列表是否包含一个坐标的点
        private bool IsInCloseList(int x, int y) {
            foreach (AStarPoint p in _closeList) {
                if (p.X == x && p.Y == y) {
                    return true;
                }
            }

            return false;
        }

        //判断开放列表是否包含一个坐标
        private bool IsInOpenList(int x, int y) {
            foreach (AStarPoint p in _openList) {
                if (p.X == x && p.Y == y) {
                    return true;
                }
            }

            return false;
        }

        //从开启列表查找F值最小的节点
        private AStarPoint GetMinFFromOpenList() {
            AStarPoint pmin = null;
            foreach (AStarPoint p in _openList) {
                if (pmin == null || pmin.G + pmin.H > p.G + p.H) {
                    pmin = p;
                }
            }

            return pmin;
        }

        //尝试获取一个有效的终点
        private bool TryGetAnValidEndPoint(Point end, out Point point) {
            //查找终点周围50层的点 在此范围内获取一个实际有效的终点
            const int searchLevel = 20;
            point = end;
            var index0 = point.Y;
            var index1 = point.X;
            if (index0 >= 0 && index1 >= 0 && index0 < _length0 && index1 < _length1 && _grid[index0, index1] == 0) {
                for (int i = 1; i < searchLevel; i++) {
                    for (int j = 0; j <= i; j++) {
                        int offsetX = i;
                        int offsetY = i - j;
                        index0 = point.Y + offsetY;
                        index1 = point.X + offsetX;
                        if (index0 >= 0 && index1 >= 0 && index0 < _length0 && index1 < _length1 &&
                            _grid[index0, index1] == 1) {
                            point = new Point(index1, index0);
                            return true;
                        }

                        index0 = point.Y + offsetY;
                        index1 = point.X + offsetX;
                        if (index0 >= 0 && index1 >= 0 && index0 < _length0 && index1 < _length1 &&
                            _grid[index0, index1] == 1) {
                            point = new Point(index1, index0);
                            return true;
                        }

                        index0 = point.Y + offsetY;
                        index1 = point.X + offsetX;
                        if (index0 >= 0 && index1 >= 0 && index0 < _length0 && index1 < _length1 &&
                            _grid[index0, index1] == 1) {
                            point = new Point(index1, index0);
                            return true;
                        }

                        index0 = point.Y + offsetY;
                        index1 = point.X + offsetX;
                        if (index0 >= 0 && index1 >= 0 && index0 < _length0 && index1 < _length1 &&
                            _grid[index0, index1] == 1) {
                            point = new Point(index1, index0);
                            return true;
                        }
                    }
                }

                return false;
            }

            return true;
        }

    }

}