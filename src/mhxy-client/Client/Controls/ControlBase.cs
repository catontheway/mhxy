// FileName:  ControlBase.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180205 13:58
// Description:   

#region

#endregion

using System;

namespace mhxy.Client.Controls {

    /// <inheritdoc />
    /// <summary>
    ///     界面控件基类
    /// </summary>
    public abstract class ControlBase : DrawableBase {

        /// <summary>
        ///     通用构造方法
        /// </summary>
        protected ControlBase() : base(DrawPriority.Normal) {
        }

        protected override void NextFrameCore() {
            throw new NotImplementedException();
        }

        protected override void DrawCore(DrawArgs args) {
            throw new NotImplementedException();
        }

    }

}