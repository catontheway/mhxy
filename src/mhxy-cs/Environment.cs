using System.IO;

namespace mhxy {

    /// <summary>
    /// 
    /// </summary>
    public static class Environment {

#if DEBUG

        /// <summary>
        /// 当前路径
        /// </summary>
        public static string CurrentDirectory = @"C:\Users\guodp\Source\mhxy";

#else

        /// <summary>
        /// 当前路径
        /// </summary>
        public static string CurrentDirectory = System.Environment.CurrentDirectory;

#endif

        /// <summary>
        /// WDF MAP文件注解文件存放目录
        /// </summary>
        public static string ConfigPath = Path.Combine(CurrentDirectory, @"data\config");

        /// <summary>
        /// WDF文件存放目录
        /// </summary>
        public static string WdfPath = Path.Combine(CurrentDirectory, @"data\wdf");

        /// <summary>
        /// MAP文件存放目录
        /// </summary>
        public static string MapPath = Path.Combine(CurrentDirectory, @"data\map");

        /// <summary>
        /// 存档目录
        /// </summary>
        public static string ProfilePath = Path.Combine(CurrentDirectory, @"data\saved");
    }

}