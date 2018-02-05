// FileName:  IDrawingService.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 08:53
// Description:   

#region

using mhxy.Common;

#endregion

namespace mhxy.Client {

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
        ///     绘制
        /// </summary>
        Canvas Draw();

        /// <summary>
        ///     更新一帧绘制内容
        /// </summary>
        void UpdateFrame();

    }

}