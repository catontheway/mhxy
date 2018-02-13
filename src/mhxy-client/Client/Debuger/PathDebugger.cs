// FileName:  PathDebugger.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180211 16:56
// Description:   

#region

using System.Drawing;

#endregion

namespace mhxy.Client.Debuger {

    public class PathDebugger : DebuggerBase {

        public override bool CanHandler(string[] args) {
            return args[0] == "g";
        }

        public override void Handler(string[] args) {
            if (args.Length < 3) {
                ServiceLocator.GlobalLogger.Warn($"Invalid GOTO Input");
                return;
            }

            int.TryParse(args[1], out int x);
            int.TryParse(args[2], out int y);
            ServiceLocator.ClientEngine.WalkTo(new Point(x, y));
        }

    }

}