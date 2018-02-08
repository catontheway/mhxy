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

        private static void Main(string[] args) {
            if (args == null || args.Length == 0) {
                args = new[] {"n"};
                //args = new[] { "m" };
            }

            ServiceLocator.GlobalLogger.Info("Application Start");
            Console.Title = Guid.NewGuid().ToString();
            IntPtr intptr = NativeMethod.FindWindow("ConsoleWindowClass", Console.Title);
            if (intptr != IntPtr.Zero) {
                NativeMethod.ShowWindow(intptr, Global.ShowConsole); //隐藏这个窗口
            }

            AppDomain.CurrentDomain.UnhandledException += CurrentDomain_UnhandledException;

            switch (args[0]) {
                case "n":
                    ServiceLocator.GlobalLogger.Info("Start Mode : Normal.");
                    ServiceLocator.ClientEngine.Start();
                    ServiceLocator.GameWindow.Run();
                    break;
                case "m":
                    ServiceLocator.GlobalLogger.Info("Start Mode : ParseAllMaps.");
                    ServiceLocator.MapManager.ParseAllMaps();
                    break;
                default:
                    ServiceLocator.GlobalLogger.Info("Start Mode : No Hit.");
                    break;
            }

            ServiceLocator.GlobalLogger.Info("Application Exit");
        }

        private static void CurrentDomain_UnhandledException(object sender, UnhandledExceptionEventArgs e) {
            ServiceLocator.GlobalLogger.Error("Unhandled Exception", e.ExceptionObject ?? e);
        }

    }

}