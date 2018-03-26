// FileName:  DebuggerContainer.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180211 17:08
// Description:   

#region

using System;
using System.Collections.Generic;
using System.Threading;

#endregion

namespace mhxy.Client.Debuger {

    /// <summary>
    ///     调试工具
    /// </summary>
    public class DebuggerContainer {

        private readonly List<DebuggerBase> _debugger = new List<DebuggerBase>();

        private void Start() {
            while (true) {
                Console.WriteLine(@"Please Input Command...");
                var line = Console.ReadLine();
                if (line != null) {
                    var args = line.Split();
                    if (args.Length <= 0) {
                        continue;
                    }

                    if (args[0] == "q") {
                        break;
                    }

                    var handlered = false;
                    foreach (var debugger in _debugger) {
                        if (debugger.CanHandler(args)) {
                            debugger.Handler(args);
                            handlered = true;
                        }
                    }

                    if (!handlered) {
                        Console.WriteLine($@"Invalid Command : {string.Join(" ", args)}");
                    }
                }
            }
        }

        public void Hook() {
            InitDebugger();
            Thread thread = new Thread(Start);
            thread.Start();
        }

        private void InitDebugger() {
            _debugger.Clear();
            _debugger.Add(new PathDebugger());
        }

    }

}