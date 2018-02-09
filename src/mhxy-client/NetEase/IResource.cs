// FileName:  IResource.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 08:53
// Description:   

#region

using System;

#endregion

namespace mhxy.NetEase {

    /// <summary>
    ///     资源接口
    /// </summary>
    public interface IResource : IDisposable {

        /// <summary>
        ///     加载资源
        /// </summary>
        void Load();

        /// <summary>
        ///     卸载资源
        /// </summary>
        void Unload();

        /// <summary>
        /// </summary>
        void Save();

    }

}