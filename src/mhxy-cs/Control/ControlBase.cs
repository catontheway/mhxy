// FileName:  ControlBase.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180201 11:27
// Description:   

using mhxy.Display;

namespace mhxy.Control {

    /// <summary>
    /// 界面控件基类
    /// </summary>
    public abstract class ControlBase : IDrawable {

        public bool Static { get; set; }

        public void NextFrame() {
            throw new System.NotImplementedException();
        }

        public void Frame(int frame) {
            throw new System.NotImplementedException();
        }

    }

}