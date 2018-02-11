using System;
using System.Drawing;

namespace mhxy.Client.AStar {

    public class AStarPoint {

        public int X { get; }
        public int Y { get; }
        public int G { get; private set; }
        public int H { get; private set; }

        public AStarPoint Parent { get; }

        public AStarPoint(int x0, int y0, AStarPoint parent, Point end) {
            X = x0;
            Y = y0;
            Parent = parent;
            GetG();
            GetH(end);
        }

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
            H = Math.Abs(X - end.X) * 10 + Math.Abs(Y - end.Y) * 10;
        }

        public override string ToString() {
            return "{" + X + "," + Y + "}";
        }
    }

}