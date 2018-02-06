﻿// FileName:  IDrawable.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180205 13:58
// Description:   

namespace mhxy.Client {

    /// <summary>
    ///     可绘制对象接口
    /// </summary>
    public interface IDrawable {

        /// <summary>
        ///     是否是静态图像
        /// </summary>
        bool Static { get; set; }

        /// <summary>
        ///     刷新到下一帧
        /// </summary>
        void NextFrame();

        /// <summary>
        ///     刷新特定帧
        /// </summary>
        void Frame(int frame);

        /// <summary>
        /// </summary>
        /// <param name="cancas"></param>
        void Draw(Canvas cancas);

    }

}