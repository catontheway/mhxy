// FileName:  GLShader.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180209 14:28
// Description:   

#region

using System.IO;
using OpenTK.Graphics.OpenGL;

#endregion

namespace mhxy.Client.OpenTk {

    /// <summary>
    /// </summary>
    public class GlShader {

        /// <summary>
        /// </summary>
        /// <param name="shaderType"></param>
        /// <param name="path"></param>
        public GlShader(ShaderType shaderType, string path) {
            _shaderId = GL.CreateShader(shaderType);
            string shaderSource = File.ReadAllText(path);
            GL.ShaderSource(_shaderId, shaderSource);
            GL.CompileShader(_shaderId);
            string error = GL.GetShaderInfoLog(_shaderId);
            _isValid = error.Length <= 0;
        }

        private readonly int _shaderId;
        private readonly bool _isValid;

        public int GetShaderId() {
            return _shaderId;
        }

        public bool IsValid() {
            return _isValid;
        }

    }

}