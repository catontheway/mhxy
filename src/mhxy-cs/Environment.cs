#define Develop

using System.IO;
namespace mhxy {

    /// <summary>
    /// 
    /// </summary>
    public static class Environment {

        static Environment() {
#if Develop
            Encrypt = true;
            Profile = false;
            CurrentDirectory = @"C:\Users\guodp\Source\mhxy";
#else
            Encrypt = true;
            Profile = true;
            CurrentDirectory = System.Environment.CurrentDirectory;
#endif
            ConfigPath = Path.Combine(CurrentDirectory, @"data\config");
            WdfPath = Path.Combine(CurrentDirectory, @"data\wdf");
            MapPath = Path.Combine(CurrentDirectory, @"data\map");
            ProfilePath = Path.Combine(CurrentDirectory, @"data\saved");
        }

        /// <summary>
        /// 是否正常登录
        /// </summary>
        public static bool Profile;

        /// <summary>
        /// 开发用户名
        /// </summary>
        public static string DevelopName = "xy";

        /// <summary>
        /// 开发密码
        /// </summary>
        public static string DevelopPwd = "guodp9u0";

        /// <summary>
        /// 开发密码
        /// </summary>
        public static int DevelopProfileId = 0;

        /// <summary>
        /// 是否加密
        /// </summary>
        public static bool Encrypt;

        /// <summary>
        /// 当前路径
        /// </summary>
        public static string CurrentDirectory;

        /// <summary>
        /// WDF MAP文件注解文件存放目录
        /// </summary>
        public static string ConfigPath;

        /// <summary>
        /// WDF文件存放目录
        /// </summary>
        public static string WdfPath;

        /// <summary>
        /// MAP文件存放目录
        /// </summary>
        public static string MapPath;

        /// <summary>
        /// 存档目录
        /// </summary>
        public static string ProfilePath;
    }

}