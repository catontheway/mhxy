// FileName:  ControlBase.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180205 13:58
// Description:   

#region

using System;

#endregion

namespace mhxy.Client.Controls {

    /// <summary>
    ///     界面控件基类
    /// </summary>
    public abstract class ControlBase : IDrawable {

        public void NextFrame() {
            throw new NotImplementedException();
        }

        public void Draw(Canvas cancas) {
            throw new NotImplementedException();
        }

    }

}