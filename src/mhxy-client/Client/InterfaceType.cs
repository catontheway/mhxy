// FileName:  InterfaceType.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 08:53
// Description:   

namespace mhxy.Client {

    /// <summary>
    ///     界面类型
    /// </summary>
    public enum InterfaceType {

        /// <summary>
        ///     开始界面
        /// </summary>
        Start

        , /// <summary>
          ///     登录界面
          /// </summary>
        SignIn

        , /// <summary>
          ///     注册界面
          /// </summary>
        SignUp

        , /// <summary>
          ///     角色选择画面
          /// </summary>
        Profile

        , /// <summary>
          ///     角色创建画面
          /// </summary>
        Create,

        /// <summary>
        ///     游戏界面
        /// </summary>
        Main,

        /// <summary>
        /// 战斗界面
        /// </summary>
        Fight,

        /// <summary>
        /// 加载画面
        /// </summary>
        Loading,

        /// <summary>
        /// 独白画面剧情使用 
        /// </summary>
        Monolog,
    }

}