using System;

namespace mhxy.Resource {

    /// <summary>
    /// Base类
    /// </summary>
    public abstract class ResourceBase : IResource {

        /// <summary>
        /// Disponse
        /// </summary>
        public void Dispose() {
            Dispose(true);
            GC.SuppressFinalize(this);
        }

        /// <summary>
        /// 加载资源
        /// </summary>
        public virtual void Load() {
            throw new System.NotImplementedException();
        }

        /// <summary>
        /// 卸载资源
        /// </summary>
        public virtual void Unload() {
            Dispose();
        }

        /// <summary>
        /// Dispose Mode
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

        private bool _disposed;
    }

}