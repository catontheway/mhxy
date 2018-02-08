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
    public abstract class ControlBase : DrawableBase {

        /// <summary>
        /// 通用构造方法
        /// </summary>
        protected ControlBase() : base(DrawPriority.Normal) {
        }
    }

}