// FileName:  Program.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 08:51
// Description:   

#region

using System;
using mhxy.Client;
using mhxy.Utils;

#endregion

namespace mhxy {

    internal class Program {

        private static void Main() {
            // 捕获未处理异常
            AppDomain.CurrentDomain.UnhandledException += CurrentDomain_UnhandledException;
            // 调试器
            if (Global.LoadDebugger) {
                ServiceLocator.DebuggerContainer.Hook();
            }

            ServiceLocator.GlobalLogger.Info("Application Start");
            // 隐藏Console 窗口
            Console.Title = Guid.NewGuid().ToString();
            IntPtr intptr = NativeMethod.FindWindow("ConsoleWindowClass", Console.Title);
            if (intptr != IntPtr.Zero) {
                NativeMethod.ShowWindow(intptr, Global.ShowConsole); //隐藏这个窗口
            }

            // 启动引擎
            ServiceLocator.ClientEngine.Start();
            //显示窗口 并运行
            ServiceLocator.Window.Show();
            //关闭窗口后停止运行
            ServiceLocator.ClientEngine.Stop();
            ServiceLocator.GlobalLogger.Info("Application Exit");
        }

        private static void CurrentDomain_UnhandledException(object sender, UnhandledExceptionEventArgs e) {
            ServiceLocator.GlobalLogger.Error("Unhandled Exception", e.ExceptionObject ?? e);
        }

    }

}