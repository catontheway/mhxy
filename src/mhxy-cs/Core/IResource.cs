using System;

namespace mhxy.Core {

    /// <summary>
    /// 资源接口
    /// </summary>
    public interface IResource : IDisposable {

        /// <summary>
        /// 加载资源
        /// </summary>
        void Load();

        /// <summary>
        /// 卸载资源
        /// </summary>
        void Unload();

    }

}