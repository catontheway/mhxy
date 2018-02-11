// FileName:  DebuggerService.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180211 17:07
// Description:   

using System;
using System.Collections.Generic;
using System.Threading;

namespace mhxy.Client.Debuger {

    /// <summary>
    /// 
    /// </summary>
    public class DebuggerContainer {

        public DebuggerContainer() {
            InitDebugger();
            Thread thread = new Thread(Start);
            thread.Start();
        }

        private void Start() {
            while (true) {
                var line = Console.ReadLine();
                if (line != null) {
                    var args = line.Split();
                    if (args.Length <= 0) {
                        continue;
                    }
                    if (args[0] == "q") {
                        break;
                    }
                    foreach (var debugger in _debugger) {
                        if (debugger.CanHandler(args)) {
                            debugger.Handler(args);
                        }
                    }
                }
            }
        }

        public void Hook() {

        }

        private readonly List<DebuggerBase> _debugger = new List<DebuggerBase>();

        private void InitDebugger() {
            _debugger.Add(new PathDebugger());
        }

    }

}