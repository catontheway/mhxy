// FileName:  IClientEngine.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 08:53
// Description:   

#region

using System.Drawing;
using mhxy.Common;
using mhxy.Common.Model;

#endregion

namespace mhxy.Client {

    /// <summary>
    ///     客户端引擎
    ///     负责数据初始化加载
    ///     数据与UI同步
    ///     界面跳转等
    /// </summary>
    public interface IClientEngine : IService {

        /// <summary>
        ///     前往界面
        /// </summary>
        /// <param name="interType">界面类型</param>
        void Goto(InterfaceType interType);

        /// <summary>
        ///     登录
        /// </summary>
        /// <param name="name"></param>
        /// <param name="pwd"></param>
        bool SignIn(string name, string pwd);

        /// <summary>
        ///     注册
        /// </summary>
        /// <param name="name"></param>
        /// <param name="pwd"></param>
        bool SignUp(string name, string pwd);

        /// <summary>
        ///     登出
        /// </summary>
        bool SignOut();

        /// <summary>
        ///     创建一个初始存档
        /// </summary>
        /// <returns></returns>
        bool CreateProfile(int id);

        /// <summary>
        ///     加载角色存档
        /// </summary>
        /// <param name="id"></param>
        bool LoadProfile(int id);

        /// <summary>
        ///     保存当前存档
        /// </summary>
        /// <returns></returns>
        bool SaveProfile();

        /// <summary>
        ///     卸载当前存档
        /// </summary>
        /// <returns></returns>
        bool UnloadProfile();

        /// <summary>
        ///     获取当前场景信息
        /// </summary>
        /// <returns></returns>
        Scene GetCurrentScene();

        /// <summary>
        ///     获取主角信息
        /// </summary>
        /// <returns></returns>
        CurrentPlayer GetCurrentPlayer();

        /// <summary>
        ///     飞行到某个场景的某个地点
        /// </summary>
        /// <param name="sceneId"></param>
        /// <param name="point"></param>
        void FlyTo(string sceneId, Point point);

        /// <summary>
        ///     走到某个地点
        /// </summary>
        /// <param name="point"></param>
        void WalkTo(Point point);

    }

}