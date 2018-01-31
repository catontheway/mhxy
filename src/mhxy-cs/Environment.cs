using System.IO;

namespace mhxy {

    /// <summary>
    /// 
    /// </summary>
    public static class Environment {

#if DEBUG

        /// <summary>
        /// WDF MAP文件注解文件存放目录
        /// </summary>
        public static string ConfigPath = @"C:\Users\guodp\Source\mhxy\data\config";

        /// <summary>
        /// WDF文件存放目录
        /// </summary>
        public static string WdfPath = @"C:\Users\guodp\Source\mhxy\data\wdf";

        /// <summary>
        /// MAP文件存放目录
        /// </summary>
        public static string MapPath = @"C:\Users\guodp\Source\mhxy\data\map";

#else

        /// <summary>
        /// WDF MAP文件注解文件存放目录
        /// </summary>
        public static string ConfigPath = Path.Combine(System.Environment.CurrentDirectory, @"data\config");

        /// <summary>
        /// WDF文件存放目录
        /// </summary>
        public static string WdfPath = Path.Combine(System.Environment.CurrentDirectory, @"data\wdf");

        /// <summary>
        /// MAP文件存放目录
        /// </summary>
        public static string MapPath = Path.Combine(System.Environment.CurrentDirectory, @"data\map");

#endif

    }

}