// FileName:  Program.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 08:51
// Description:   

#region

using System;
using mhxy.Client;
using mhxy.Client.Debuger;
using mhxy.Utils;

#endregion

namespace mhxy {

    internal class Program {

        private static void Main() {
            ServiceLocator.GlobalLogger.Info("Application Start");
            // 隐藏Console 窗口
            Console.Title = Guid.NewGuid().ToString();
            IntPtr intptr = NativeMethod.FindWindow("ConsoleWindowClass", Console.Title);
            if (intptr != IntPtr.Zero) {
                NativeMethod.ShowWindow(intptr, Global.ShowConsole); //隐藏这个窗口
            }

            // 捕获未处理异常
            AppDomain.CurrentDomain.UnhandledException += CurrentDomain_UnhandledException;
            ServiceLocator.ClientEngine.Start();
            DebuggerContainer container = new DebuggerContainer();
            container.Hook();
            ServiceLocator.Window.RunDefault();
            ServiceLocator.GlobalLogger.Info("Application Exit");
        }


        private static void CurrentDomain_UnhandledException(object sender, UnhandledExceptionEventArgs e) {
            ServiceLocator.GlobalLogger.Error("Unhandled Exception", e.ExceptionObject ?? e);
        }

    }

}