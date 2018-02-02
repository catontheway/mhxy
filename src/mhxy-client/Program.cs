// FileName:  Program.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 08:51
// Description:   

#region

using System;
using System.Runtime.InteropServices;
using mhxy.Client;

#endregion

namespace mhxy {

    internal class Program {

        [DllImport("user32.dll", EntryPoint = "ShowWindow", SetLastError = true)]
        private static extern bool ShowWindow(IntPtr hWnd, uint nCmdShow);

        [DllImport("user32.dll", EntryPoint = "FindWindow", SetLastError = true)]
        public static extern IntPtr FindWindow(string lpClassName, string lpWindowName);

        private static void Main() {
            ServiceLocator.AppLogger.Info("Application Start");
            IntPtr intptr = FindWindow("ConsoleWindowClass", Console.Title);
            if (intptr != IntPtr.Zero) {
                ShowWindow(intptr, Environment.ShowConsole); //隐藏这个窗口
            }

            AppDomain.CurrentDomain.UnhandledException += CurrentDomain_UnhandledException;
            Console.Title = Guid.NewGuid().ToString();
            ServiceLocator.ClientEngine.Start();
            ServiceLocator.GameWindow.Run();
            ServiceLocator.AppLogger.Info("Application Exit");
        }

        private static void CurrentDomain_UnhandledException(object sender, UnhandledExceptionEventArgs e) {
            ServiceLocator.AppLogger.Error("Unhandled Exception", e.ExceptionObject ?? e);
        }

    }

}