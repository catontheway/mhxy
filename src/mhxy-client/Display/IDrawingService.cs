// FileName:  IDrawingService.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 08:53
// Description:   

#region

using mhxy.Common;

#endregion

namespace mhxy.Display {

    /// <summary>
    ///     绘制服务
    /// </summary>
    public interface IDrawingService : IService {

        /// <summary>
        ///     添加可绘制对象到绘制层
        /// </summary>
        /// <param name="drawableObj"></param>
        void Add(IDrawable drawableObj);

        /// <summary>
        ///     移除可绘制对象
        /// </summary>
        /// <param name="drawableObj"></param>
        void Remove(IDrawable drawableObj);

        /// <summary>
        ///     移除全部可绘制对象
        /// </summary>
        void RemoveAll();

        /// <summary>
        ///     更新可绘制对象(移除并重新添加)
        /// </summary>
        /// <param name="drawableObj"></param>
        void Update(IDrawable drawableObj);

        /// <summary>
        ///     绘制
        /// </summary>
        void Draw();

        /// <summary>
        ///     更新一帧绘制内容
        /// </summary>
        void UpdateFrame();

    }

}