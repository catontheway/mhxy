// FileName:  JSONUtil.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180201 14:52
// Description:   

using System;

namespace mhxy.Utils {

    /// <summary>
    /// JSON 帮助类
    /// </summary>
    public static class JsonUtil {

        /// <summary>
        /// 序列化
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <param name="obj">对象</param>
        /// <param name="result">json</param>
        /// <returns></returns>
        public static bool TryToJson<T>(T obj, out string result) {
            result = string.Empty;
            try {
                result = fastJSON.JSON.ToJSON(obj);
                return true;
            } catch (Exception e) {
                ServiceLocator.AppLogger.Error(e);
                return false;
            }
        }

        /// <summary>
        /// 反序列化
        /// </summary>
        /// <typeparam name="T">type</typeparam>
        /// <param name="json">json</param>
        /// <param name="result">结果</param>
        /// <returns></returns>
        public static bool TryToObject<T>(string json, out T result) {
            result = default(T);
            try {
                result = fastJSON.JSON.ToObject<T>(json);
                return true;
            } catch (Exception e) {
                ServiceLocator.AppLogger.Error(e);
                return false;
            }
        }

    }
}