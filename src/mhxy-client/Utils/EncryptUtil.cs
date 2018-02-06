// FileName:  EncryptUtil.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 08:53
// Description:   

#region

using System;
using System.Collections.Generic;
using System.IO;
using System.Security.Cryptography;
using System.Text;

#endregion

namespace mhxy.Utils {

    public static class EncryptUtil {

        #region MD5加密

        /// <summary>
        ///     MD5加密
        /// </summary>
        public static string Md532(this string value) {
            if (value == null) {
                throw new ArgumentNullException(nameof(value));
            }

            var encoding = Encoding.UTF8;
            MD5 md5 = MD5.Create();
            return HashAlgorithmBase(md5, value, encoding);
        }

        /// <summary>
        ///     加权MD5加密
        /// </summary>
        public static string Md532(this string value, string salt) {
            return salt == null ? value.Md532() : (value + "『" + salt + "』").Md532();
        }

        #endregion

        #region AES 加密解密

        /// <summary>
        ///     AES加密
        /// </summary>
        /// <param name="data">被加密的明文</param>
        /// <param name="key">密钥</param>
        /// <param name="vector">向量</param>
        /// <returns>密文</returns>
        public static string AesEncrypt(this string data, string key, string vector) {
            byte[] plainBytes = Encoding.UTF8.GetBytes(data);
            byte[] bKey = new byte[32];
            Array.Copy(Encoding.UTF8.GetBytes(key.PadRight(bKey.Length)), bKey, bKey.Length);
            byte[] bVector = new byte[16];
            Array.Copy(Encoding.UTF8.GetBytes(vector.PadRight(bVector.Length)), bVector, bVector.Length);
            byte[] cryptograph; // 加密后的密文  
            Rijndael aes = Rijndael.Create();
            // 开辟一块内存流  
            using (var memory = new MemoryStream()) {
                // 把内存流对象包装成加密流对象  
                using (var encryptor = new CryptoStream(memory,
                    aes.CreateEncryptor(bKey, bVector),
                    CryptoStreamMode.Write)) {
                    // 明文数据写入加密流  
                    encryptor.Write(plainBytes, 0, plainBytes.Length);
                    encryptor.FlushFinalBlock();
                    cryptograph = memory.ToArray();
                }
            }

            return Convert.ToBase64String(cryptograph);
        }

        /// <summary>
        ///     AES解密
        /// </summary>
        /// <param name="data">被解密的密文</param>
        /// <param name="key">密钥</param>
        /// <param name="vector">向量</param>
        /// <returns>明文</returns>
        public static string AesDecrypt(this string data, string key, string vector) {
            byte[] encryptedBytes = Convert.FromBase64String(data);
            byte[] bKey = new byte[32];
            Array.Copy(Encoding.UTF8.GetBytes(key.PadRight(bKey.Length)), bKey, bKey.Length);
            byte[] bVector = new byte[16];
            Array.Copy(Encoding.UTF8.GetBytes(vector.PadRight(bVector.Length)), bVector, bVector.Length);
            byte[] original; // 解密后的明文  
            Rijndael aes = Rijndael.Create();
            // 开辟一块内存流，存储密文  
            using (MemoryStream memory = new MemoryStream(encryptedBytes)) {
                // 把内存流对象包装成加密流对象  
                using (CryptoStream decryptor = new CryptoStream(memory,
                    aes.CreateDecryptor(bKey, bVector),
                    CryptoStreamMode.Read)) {
                    // 明文存储区  
                    using (MemoryStream originalMemory = new MemoryStream()) {
                        byte[] buffer = new byte[1024];
                        int readBytes;
                        while ((readBytes = decryptor.Read(buffer, 0, buffer.Length)) > 0) {
                            originalMemory.Write(buffer, 0, readBytes);
                        }

                        original = originalMemory.ToArray();
                    }
                }
            }

            return Encoding.UTF8.GetString(original);
        }


        /// <summary>
        ///     AES加密(无向量)
        /// </summary>
        /// <param name="data">被加密的明文</param>
        /// <param name="key">密钥</param>
        /// <returns>密文</returns>
        public static string AesEncrypt(this string data, string key) {
            MemoryStream mStream = new MemoryStream();
            RijndaelManaged aes = new RijndaelManaged();

            byte[] plainBytes = Encoding.UTF8.GetBytes(data);
            byte[] bKey = new byte[32];
            Array.Copy(Encoding.UTF8.GetBytes(key.PadRight(bKey.Length)), bKey, bKey.Length);

            aes.Mode = CipherMode.ECB;
            aes.Padding = PaddingMode.PKCS7;
            aes.KeySize = 128;
            //aes.Key = _key;  
            aes.Key = bKey;
            //aes.IV = _iV;  
            CryptoStream cryptoStream = new CryptoStream(mStream, aes.CreateEncryptor(), CryptoStreamMode.Write);
            try {
                cryptoStream.Write(plainBytes, 0, plainBytes.Length);
                cryptoStream.FlushFinalBlock();
                return Convert.ToBase64String(mStream.ToArray());
            } finally {
                cryptoStream.Close();
                mStream.Close();
                aes.Clear();
            }
        }


        /// <summary>
        ///     AES解密(无向量)
        /// </summary>
        /// <param name="data">被加密的明文</param>
        /// <param name="key"></param>
        /// <returns>明文</returns>
        public static string AesDecrypt(this string data, string key) {
            byte[] encryptedBytes = Convert.FromBase64String(data);
            byte[] bKey = new byte[32];
            Array.Copy(Encoding.UTF8.GetBytes(key.PadRight(bKey.Length)), bKey, bKey.Length);

            MemoryStream mStream = new MemoryStream(encryptedBytes);
            //mStream.Write( encryptedBytes, 0, encryptedBytes.Length );  
            //mStream.Seek( 0, SeekOrigin.Begin );  
            RijndaelManaged aes = new RijndaelManaged {
                Mode = CipherMode.ECB,
                Padding = PaddingMode.PKCS7,
                KeySize = 128,
                Key = bKey
            };
            //aes.IV = _iV;  
            CryptoStream cryptoStream = new CryptoStream(mStream, aes.CreateDecryptor(), CryptoStreamMode.Read);
            try {
                byte[] tmp = new byte[encryptedBytes.Length + 32];
                int len = cryptoStream.Read(tmp, 0, encryptedBytes.Length + 32);
                byte[] ret = new byte[len];
                Array.Copy(tmp, 0, ret, 0, len);
                return Encoding.UTF8.GetString(ret);
            } finally {
                cryptoStream.Close();
                mStream.Close();
                aes.Clear();
            }
        }

        #endregion

        #region Base64加密解密

        /// <summary>
        ///     Base64加密 可逆
        /// </summary>
        /// <param name="value">待加密文本</param>
        /// <returns></returns>
        public static string Base64Encrypt(string value) {
            return Convert.ToBase64String(Encoding.Default.GetBytes(value));
        }

        /// <summary>
        ///     Base64解密
        /// </summary>
        /// <param name="ciphervalue">密文</param>
        /// <returns></returns>
        public static string Base64Decrypt(string ciphervalue) {
            return Encoding.Default.GetString(Convert.FromBase64String(ciphervalue));
        }

        #endregion

        #region 内部方法

        /// <summary>
        ///     转成数组
        /// </summary>
        /// <summary>
        ///     转换成字符串
        /// </summary>
        private static string Bytes2Str(this IEnumerable<byte> source, string formatStr = "{0:X2}") {
            StringBuilder pwd = new StringBuilder();
            foreach (byte btStr in source) {
                pwd.AppendFormat(formatStr, btStr);
            }

            return pwd.ToString();
        }

        /// <summary>
        ///     HashAlgorithm 加密统一方法
        /// </summary>
        private static string HashAlgorithmBase(HashAlgorithm hashAlgorithmObj, string source, Encoding encoding) {
            byte[] btStr = encoding.GetBytes(source);
            byte[] hashStr = hashAlgorithmObj.ComputeHash(btStr);
            return hashStr.Bytes2Str();
        }

        #endregion

    }

}