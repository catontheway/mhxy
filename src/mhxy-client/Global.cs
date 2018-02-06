// FileName:  Environment.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 08:53
// Description:   

#define Develop

#region

using System;
using System.IO;

#endregion

namespace mhxy {

    /// <summary>
    /// </summary>
    public static class Global {

        /// <summary>
        ///     Map Cell 宽度
        /// </summary>
        public const int WidthPerMapCell = 320;

        /// <summary>
        ///     Map Cell 高度
        /// </summary>
        public const int HeightPerMapCell = 240;

        // 非正常情况下：地图到达边缘 需要保持地图不变 移动主角到屏幕边缘

        /// <summary>
        ///     主角在屏幕上的位置(正常情况下)
        /// </summary>
        public const int PlayX = 400;

        /// <summary>
        ///     主角在屏幕上的位置(正常情况下)
        /// </summary>
        public const int PlayY = 300;

        /// <summary>
        ///     是否正常登录
        /// </summary>
        public static bool Profile;

        /// <summary>
        ///     开发用户名
        /// </summary>
        public static string DevelopName = DateTime.Now.ToString("yyyyMMddHHmmss");

        /// <summary>
        ///     开发密码
        /// </summary>
        public static string DevelopPwd = "guodp9u0";

        /// <summary>
        ///     开发存档编号
        /// </summary>
        public static int DevelopProfileId = 0;

        /// <summary>
        ///     是否加密
        /// </summary>
        public static bool Encrypt;

        /// <summary>
        ///     是否显示启动的Console窗口(该窗口会输出日志)
        /// </summary>
        public static uint ShowConsole;

        /// <summary>
        ///     当前路径
        /// </summary>
        public static string CurrentDirectory;

        /// <summary>
        ///     WDF MAP文件注解文件存放目录
        /// </summary>
        public static string ConfigPath;

        /// <summary>
        ///     WDF文件存放目录
        /// </summary>
        public static string WdfPath;

        /// <summary>
        ///     MAP文件存放目录
        /// </summary>
        public static string MapPath;

        /// <summary>
        ///     存档目录
        /// </summary>
        public static string ProfilePath;

        /// <summary>
        ///     宽度
        /// </summary>
        public static int Width = 800;

        /// <summary>
        ///     高度
        /// </summary>
        public static int Height = 600;

        /// <summary>
        /// </summary>
        public static string Title = @"梦幻西游";

        /// <summary>
        ///     帧
        /// </summary>
        public static int FramePerSecond = 60;

        static Global() {
#if Develop
            Encrypt = false;
            Profile = false;
            CurrentDirectory = @"C:\Users\guodp\Source\mhxy";
            ShowConsole = 1;
#else
            Encrypt = true;
            Profile = true;
            CurrentDirectory = System.Environment.CurrentDirectory;
            ShowConsole = 0;
#endif
            ConfigPath = Path.Combine(CurrentDirectory, @"data\config");
            WdfPath = Path.Combine(CurrentDirectory, @"data\wdf");
            MapPath = Path.Combine(CurrentDirectory, @"data\map");
            ProfilePath = Path.Combine(CurrentDirectory, @"data\saved");
        }

    }

}