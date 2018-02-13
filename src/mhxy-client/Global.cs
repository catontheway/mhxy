// FileName:  Global.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 18:05
// Description:   

#define Develop

#region

using System.IO;

#endregion

namespace mhxy {

    /// <summary>
    ///     全局常量定义
    /// </summary>
    public static class Global {

        /// <summary>
        ///     Map Unit 图片宽度
        /// </summary>
        public const int ImageWidthPerMapUnit = 320;

        /// <summary>
        ///     Map Unit 图片高度
        /// </summary>
        public const int ImageHeightPerMapUnit = 240;

        /// <summary>
        ///     Map Unit Cell宽度
        /// </summary>
        public const int CellWidthPerMapUnit = 16;

        /// <summary>
        ///     Map Unit Cell高度
        /// </summary>
        public const int CellHeightPerMapUnit = 12;

        /// <summary>
        ///     每个Cell的像素点
        /// </summary>
        public const int PixelPerCell = 20;

        /// <summary>
        ///     主角在屏幕上的位置(正常情况下)
        /// </summary>
        public const int PlayY = Height / 2;

        /// <summary>
        ///     宽度
        /// </summary>
        public const int Width = 800;

        /// <summary>
        ///     高度
        /// </summary>
        public const int Height = 600;

        // 非正常情况下：地图到达边缘 需要保持地图不变 移动主角到屏幕边缘

        /// <summary>
        ///     主角在屏幕上的位置(正常情况下)
        /// </summary>
        public static int PlayX = Width / 2;

        /// <summary>
        ///     是否正常登录
        /// </summary>
        public static bool Profile;

        /// <summary>
        ///     开发用户名
        /// </summary>
        public static string DevelopName = "guodp9u0";

        /// <summary>
        ///     开发密码
        /// </summary>
        public static string DevelopPwd = "guodp9u0";

        /// <summary>
        ///     开发存档编号
        /// </summary>
        public static int DevelopProfileId = 1;

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
        /// </summary>
        public static string Title = @"";

        /// <summary>
        ///     画面更新频率
        /// </summary>
        public static int FramePerSecond = 20;

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