// FileName:  ArrayExtensions.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 10:51
// Description:   

#region

using System;

#endregion

namespace mhxy.Utils {

    /// <summary>
    ///     数组扩展方法
    /// </summary>
    public static class ArrayExtensions {

        /// <summary>
        ///     复制一份新的二维灰度数组
        /// </summary>
        public static byte[,] Copy(this byte[,] bytes) {
            int width = bytes.GetLength(0), height = bytes.GetLength(1);
            var newBytes = new byte[width, height];
            Array.Copy(bytes, newBytes, bytes.Length);
            return newBytes;
        }


        /// <summary>
        ///     bytes 转int
        /// </summary>
        /// <param name="bytes"></param>
        /// <returns></returns>
        public static int BytesToInt(this byte[] bytes) {
            return (bytes[0] & 0xFF) |
                   ((bytes[1] & 0xFF) << 8) |
                   ((bytes[2] & 0xFF) << 16) |
                   ((bytes[3] & 0xFF) << 24);
        }

    }

}