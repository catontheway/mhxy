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
    public static class Environment {

        /// <summary>
        ///     是否正常登录
        /// </summary>
        public static bool Profile;

        /// <summary>
        ///     开发用户名
        /// </summary>
        public static string DevelopName = Guid.NewGuid().ToString();

        /// <summary>
        ///     开发密码
        /// </summary>
        public static string DevelopPwd = "guodp9u0";

        /// <summary>
        ///     开发密码
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
        /// 帧
        /// </summary>
        public static int FramePerSecond = 60;

        static Environment() {
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