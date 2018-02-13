// FileName:  AStarPoint.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180211 15:54
// Description:   

#region

using System;
using System.Diagnostics;
using System.Drawing;

#endregion

namespace mhxy.Client.AStar {

    /// <summary>
    ///     A* 算法点
    /// </summary>
    [DebuggerDisplay("{X} {Y} {G} {H}: {G+H}")]
    public class AStarPoint {

        /// <summary>
        ///     A* 算法点
        /// </summary>
        /// <param name="x0">坐标</param>
        /// <param name="y0">坐标</param>
        /// <param name="parent">父节点</param>
        /// <param name="end">终点</param>
        public AStarPoint(int x0, int y0, AStarPoint parent, Point end) {
            X = x0;
            Y = y0;
            Parent = parent;
            GetG();
            GetH(end);
        }

        /// <summary>
        ///     坐标
        /// </summary>

        public int X { get; }

        /// <summary>
        ///     坐标
        /// </summary>
        public int Y { get; }

        /// <summary>
        ///     开始点到当前点的开销
        /// </summary>
        public int G { get; private set; }

        /// <summary>
        ///     当前点到终点的预计开销
        /// </summary>
        public int H { get; private set; }

        /// <summary>
        ///     父节点
        /// </summary>
        public AStarPoint Parent { get; }

        private void GetG() {
            if (Parent == null) {
                G = 0;
            } else if (X == Parent.X || Y == Parent.Y) {
                G = Parent.G + 10;
            } else {
                G = Parent.G + 14;
            }
        }

        private void GetH(Point end) {
            var distX = Math.Abs(X - end.X);
            var distY = Math.Abs(Y - end.Y);
            H = Math.Abs(distX - distY) * 10 + Math.Min(distX, distY) * 14;
            //H = Math.Abs(X - end.X) * 10 + Math.Abs(Y - end.Y) * 10;
        }

    }

}