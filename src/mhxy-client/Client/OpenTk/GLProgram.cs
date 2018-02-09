// FileName:  GLProgram.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180209 14:28
// Description:   

#region

using System;
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
            GL.AttachShader(_program, _vertexShader.GetShaderId());
            GL.AttachShader(_program, _fragmentShader.GetShaderId());

            if (_geometryShader != null) {
                GL.AttachShader(_program, _geometryShader.GetShaderId());
            }

            GL.LinkProgram(_program);
            string error = GL.GetProgramInfoLog(_program);
            if (error.Length > 0) {
                _mIsValid = false;
                Console.WriteLine(error);
            } else {
                _mIsValid = true;
            }
        }

        private readonly int _program;
        private readonly GlShader _vertexShader;
        private readonly GlShader _fragmentShader;
        private readonly GlShader _geometryShader;
        private readonly bool _mIsValid;

        public void Use() {
            GL.UseProgram(_program);
        }

        public int GetUniformLocation(string name) {
            return GL.GetUniformLocation(_program, name);
        }

        public bool IsValid() {
            return _mIsValid;
        }

    }

}