// FileName:  AStarFinder.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180211 15:53
// Description:   

using System.Collections.Generic;
using System.Drawing;

namespace mhxy.Client.AStar {


    /// <summary>
    /// 
    /// </summary>
    public class AStarFinder {

        private readonly List<AStarPoint> _openList = new List<AStarPoint>();
        private readonly List<AStarPoint> _closeList = new List<AStarPoint>();
        private readonly int _length0;
        private readonly int _length1;
        private readonly byte[,] _grid;

        /// <summary>
        /// 
        /// </summary>
        /// <param name="grid"></param>
        public AStarFinder(byte[,] grid) {
            _grid = grid;
            _length0 = _grid.GetLength(0);
            _length1 = _grid.GetLength(1);
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="start"></param>
        /// <param name="end"></param>
        /// <returns></returns>
        public List<Point> FindPath(Point start, Point end) {
            List<Point> way = new List<Point>();
            if (start.X < 0 || start.X >= _length0 || start.Y < 0 || start.Y >= _length1 ||
                _grid[start.X, start.Y] == 0) {
                return way;
            }
            if (!TryGetAnValidEndPoint(end, out end)) {
                return way;
            }
            var startPoint = new AStarPoint(start.X, start.Y, null, end);
            AddToOpenList(startPoint);
            AStarPoint current = startPoint;
            while (!OpenListIsEmpty()) {
                current = GetMinFFromOpenList();
                if (current.X == end.X && current.Y == end.Y) {
                    break;// Success
                }
                RemoveFromOpenList(current);
                AddToCloseList(current);
                Check8(current, end);
            }
            while (current != null) {
                way.Add(new Point(current.X, current.Y));
                current = current.Parent;
            }
            return way;
        }

        private void Check8(AStarPoint current, Point end) {
            for (int indexX = current.X - 1; indexX < current.X + 2; indexX++) {
                for (int indexY = current.Y - 1; indexY < current.Y + 2; indexY++) {
                    if (indexX == end.X && indexY == end.Y) {
                    }
                    var point = new AStarPoint(indexX, indexY, current, end);
                    if (indexX == current.X && indexY == current.Y
                        || indexX < 0 || indexX >= _length0 || indexY < 0 || indexY >= _length1
                        || _grid[indexX, indexY] == 0
                        || IsInOpenList(indexX, indexY)
                        || IsInCloseList(indexX, indexY)) {
                        continue;
                    } else {
                        //var point = new AStarPoint(indexX, indexY, current, end);
                        AddToOpenList(point);
                        ServiceLocator.GlobalLogger.Debug($"Add To OpenList {point.X} {point.Y} {point.G} {point.H}");
                    }
                }
            }
        }

        /// <summary>
        /// 
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

        private const int SearchLevel = 30;

        private bool TryGetAnValidEndPoint(Point end, out Point point) {
            point = end;
            var indexX = point.X;
            var indexY = point.Y;
            if (indexX >= 0 && indexY >= 0 && indexX < _length0 && indexY < _length1 && _grid[indexX, indexY] == 0) {
                for (int i = 1; i < SearchLevel; i++) {
                    for (int j = 0; j <= i; j++) {
                        int offsetX = i;
                        int offsetY = i - j;
                        indexX = point.X + offsetX;
                        indexY = point.Y + offsetY;
                        if (indexX >= 0 && indexY >= 0 && indexX < _length0 && indexY < _length1 && _grid[indexX, indexY] == 1) {
                            point = new Point(indexX, indexY);
                            return true;
                        }
                        indexX = point.X + offsetX;
                        indexY = point.Y - offsetY;
                        if (indexX >= 0 && indexY >= 0 && indexX < _length0 && indexY < _length1 && _grid[indexX, indexY] == 1) {
                            point = new Point(indexX, indexY);
                            return true;
                        }
                        indexX = point.X - offsetX;
                        indexY = point.Y + offsetY;
                        if (indexX >= 0 && indexY >= 0 && indexX < _length0 && indexY < _length1 && _grid[indexX, indexY] == 1) {
                            point = new Point(indexX, indexY);
                            return true;
                        }
                        indexX = point.X - offsetX;
                        indexY = point.Y - offsetY;
                        if (indexX >= 0 && indexY >= 0 && indexX < _length0 && indexY < _length1 && _grid[indexX, indexY] == 1) {
                            point = new Point(indexX, indexY);
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