// FileName:  DebuggerBase.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180211 16:56
// Description:   

namespace mhxy.Client.Debuger {

    /// <summary>
    /// 调试器基类
    /// </summary>
    public abstract class DebuggerBase {


        /// <summary>
        /// 是否是处理某个输入的调试器
        /// </summary>
        /// <param name="args"></param>
        /// <returns></returns>
        public abstract bool CanHandler(string[] args);

        /// <summary>
        /// 处理参数
        /// </summary>
        /// <param name="args"></param>
        public abstract void Handler(string[] args);

    }

}