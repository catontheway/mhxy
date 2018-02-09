// FileName:  ResourceBase.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 08:53
// Description:   

#region

using System;
using mhxy.Logging;

#endregion

namespace mhxy.NetEase {

    /// <summary>
    ///     Base类
    /// </summary>
    public abstract class ResourceBase : IResource {

        protected ResourceBase() {
            Logger = LogManager.GetLogger(this);
        }

        private bool _disposed;

        protected ILogger Logger { get; }

        /// <summary>
        ///     Disponse
        /// </summary>
        public void Dispose() {
            Dispose(true);
            GC.SuppressFinalize(this);
        }

        /// <summary>
        ///     加载资源
        /// </summary>
        public virtual void Load() {
            throw new NotImplementedException();
        }

        /// <summary>
        ///     卸载资源
        /// </summary>
        public virtual void Unload() {
            Dispose();
        }

        /// <summary>
        ///     保存资源
        /// </summary>
        public virtual void Save() {
            throw new NotImplementedException();
        }

        /// <summary>
        ///     Dispose Mode
        /// </summary>
        /// <param name="disposing"></param>
        protected virtual void Dispose(bool disposing) {
            if (!_disposed) {
                if (disposing) {
                    //Release managed resources
                }

                //Release unmanaged resources
                _disposed = true;
            }
        }

        //Finalize()
        ~ResourceBase() {
            Dispose(false);
        }

    }

}