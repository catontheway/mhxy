// FileName:  InterfaceBase.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 08:53
// Description:   

#region

using mhxy.Logging;

#endregion

namespace mhxy.Client {

    /// <summary>
    ///     界面基类
    /// </summary>
    public abstract class InterfaceBase {

        protected InterfaceBase() {
            Logger = LogManager.GetLogger(this);
        }

        protected ILogger Logger;

        /// <summary>
        ///     InterfaceType
        /// </summary>
        public abstract InterfaceType Type { get; }

        /// <summary>
        ///     开始绘制
        /// </summary>
        public void Show() {
            Logger.Info($"{Type} Show");
            ShowCore();
        }

        /// <summary>
        ///     停止绘制
        /// </summary>
        public void Close() {
            Logger.Info($"{Type} Close");
            CloseCore();
        }

        /// <summary>
        ///     虚方法 供派生类调用
        /// </summary>
        protected virtual void ShowCore() {
        }

        /// <summary>
        ///     虚方法 供派生类调用
        /// </summary>
        protected virtual void CloseCore() {
        }

    }

}