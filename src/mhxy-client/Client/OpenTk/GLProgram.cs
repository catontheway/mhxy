// FileName:  GLProgram.cs
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
    public class GlProgram {

        /// <summary>
        /// </summary>
        /// <param name="vertPath"></param>
        /// <param name="fragPath"></param>
        /// <param name="geomPath"></param>
        public GlProgram(string vertPath = "", string fragPath = "", string geomPath = "") {
            if (vertPath.Length > 0) {
                _vertexShader = new GlShader(ShaderType.VertexShader, vertPath);
            }

            if (fragPath.Length > 0) {
                _fragmentShader = new GlShader(ShaderType.FragmentShader, fragPath);
            }

            if (geomPath.Length > 0) {
                _geometryShader = new GlShader(ShaderType.GeometryShader, geomPath);
            }

            _program = GL.CreateProgram();

            if (_vertexShader != null) {
                GL.AttachShader(_program, _vertexShader.GetShaderId());
            }

            if (_fragmentShader != null) {
                GL.AttachShader(_program, _fragmentShader.GetShaderId());
            }

            if (_geometryShader != null) {
                GL.AttachShader(_program, _geometryShader.GetShaderId());
            }

            GL.LinkProgram(_program);
            string error = GL.GetProgramInfoLog(_program);
            if (error.Length > 0) {
                _isValid = false;
                ServiceLocator.GlobalLogger.Error(error);
            } else {
                _isValid = true;
            }
        }

        private readonly int _program;
        private readonly bool _isValid;
        private readonly GlShader _vertexShader;
        private readonly GlShader _fragmentShader;
        private readonly GlShader _geometryShader;

        public void Use() {
            GL.UseProgram(_program);
        }

        public int GetUniformLocation(string name) {
            if (!_isValid) {
                throw new InvalidDataException("Is Not Valid");
            }

            return GL.GetUniformLocation(_program, name);
        }

        public bool IsValid() {
            return _isValid;
        }

    }

}