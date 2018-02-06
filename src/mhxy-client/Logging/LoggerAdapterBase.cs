﻿// FileName:  LoggerAdapterBase.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 08:53
// Description:   

#region

using System;
using System.Collections.Concurrent;
using mhxy.Utils;

#endregion

namespace mhxy.Logging {

    /// <summary>
    ///     按名称缓存的日志实现适配器基类，用于创建并管理指定类型的日志实例
    /// </summary>
    public abstract class LoggerAdapterBase : ILoggerAdapter {

        /// <summary>
        ///     初始化一个<see cref="LoggerAdapterBase" />类型的新实例
        /// </summary>
        protected LoggerAdapterBase() {
            _cacheLoggers = new ConcurrentDictionary<string, ILog>();
        }

        private readonly ConcurrentDictionary<string, ILog> _cacheLoggers;

        /// <summary>
        ///     创建指定名称的缓存实例
        /// </summary>
        /// <param name="name">指定名称</param>
        /// <returns></returns>
        protected abstract ILog CreateLogger(string name);

        /// <summary>
        ///     清除缓存中的日志实例
        /// </summary>
        protected virtual void ClearLoggerCache() {
            _cacheLoggers.Clear();
        }

        /// <summary>
        ///     获取指定名称的Logger实例
        /// </summary>
        /// <param name="name">指定名称</param>
        /// <returns>日志实例</returns>
        /// <exception cref="NotSupportedException">指定名称的日志缓存实例不存在则返回异常<see cref="NotSupportedException" /></exception>
        protected virtual ILog GetLoggerInternal(string name) {
            if (_cacheLoggers.TryGetValue(name, out ILog log))
                return log;
            log = CreateLogger(name);
            _cacheLoggers[name] = log ?? throw new NotSupportedException(
                                      Resources.Logging_CreateLogInstanceReturnNull.FormatWith(name
                                          , GetType().FullName));
            return log;
        }

        #region Implementation of ILoggerFactoryAdapter

        /// <summary>
        ///     由指定类型获取<see cref="ILog" />日志实例
        /// </summary>
        /// <param name="type">指定类型</param>
        /// <returns></returns>
        public ILog GetLogger(Type type) {
            type.CheckNotNull("type");
            return GetLogger(type.FullName);
        }

        /// <summary>
        ///     由指定名称获取<see cref="ILog" />日志实例
        /// </summary>
        /// <param name="name">指定名称</param>
        /// <returns></returns>
        public ILog GetLogger(string name) {
            name.CheckNotNullOrEmpty("name");
            return GetLoggerInternal(name);
        }

        #endregion

    }

}