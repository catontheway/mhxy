// FileName:  DebuggerBase.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180211 16:56
// Description:   

namespace mhxy.Client.Debuger {

    /// <summary>
    /// </summary>
    public abstract class DebuggerBase {

        public abstract bool CanHandler(string[] args);

        public abstract void Handler(string[] args);

    }

}