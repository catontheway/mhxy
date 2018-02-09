// FileName:  ClientEngine.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 08:53
// Description:   

#region

using System.Collections.Generic;
using System.Drawing;
using mhxy.Client.Interfaces;
using mhxy.Common;
using mhxy.Common.Model;
using mhxy.NetEase.Profiles;
using mhxy.Utils;

#endregion

namespace mhxy.Client {

    /// <summary>
    /// </summary>
    public class ClientEngine : ServiceBase, IClientEngine {

        public ClientEngine() {
            InitializeInterfaces();
        }

        private readonly Dictionary<InterfaceType, InterfaceBase> _interfaces =
            new Dictionary<InterfaceType, InterfaceBase>();

        private InterfaceBase _currentInterface;
        private bool _signedIn;
        private string _currentName;
        private string _currentPwd;
        private int _currentProfilId;
        private Profile _currentProfile = new Profile {InitCreate = true};
        private Scene _currentScene = new Scene();
        private CurrentPlayer _currentPlayer = CurrentPlayer.None;

        /// <summary>
        ///     前往某个界面
        /// </summary>
        /// <param name="interType"></param>
        public void Goto(InterfaceType interType) {
            Logger.Info($"Goto : {interType}");
            _currentInterface?.Close();
            _currentInterface = _interfaces[interType];
            _currentInterface?.Show();
        }

        /// <summary>
        /// </summary>
        /// <returns></returns>
        public bool SaveProfile() {
            Logger.Info("SaveProfile");
            _currentProfile.InitCreate = false;
            return ServiceLocator.ProfileService.SaveProfile(_currentName, _currentPwd, _currentProfilId
                , _currentProfile);
        }

        public bool LoadProfile(int id) {
            Logger.Info($"LoadProfile : {_currentName} {id}");
            if (ServiceLocator.ProfileService.TryReadProfile(_currentName, _currentPwd, id, out Profile profile)) {
                var scene = new Scene {
                    MapId = _currentProfile.MapId
                };
                var player = new CurrentPlayer {
                    At = _currentProfile.PlayerAt,
                    FaceTo = Direction.Down,
                    Role = _currentProfile.Role,
                    Level = _currentPlayer.Level
                };
                _currentScene = scene;
                _currentPlayer = player;
                _currentProfilId = id;
                _currentProfile = profile;
                return true;
            }

            return false;
        }

        /// <summary>
        ///     注册
        /// </summary>
        /// <param name="name"></param>
        /// <param name="pwd"></param>
        /// <returns></returns>
        public bool SignUp(string name, string pwd) {
            Logger.Info($"SignUp : {name} {pwd}");
            return !ServiceLocator.ProfileService.Has(name) && ServiceLocator.ProfileService.Create(name, pwd.Md532());
        }

        /// <summary>
        ///     登录
        /// </summary>
        /// <param name="name"></param>
        /// <param name="pwd"></param>
        /// <returns></returns>
        public bool SignIn(string name, string pwd) {
            Logger.Info($"SignIn : {name} {pwd}");
            if (!_signedIn && ServiceLocator.ProfileService.Has(name)) {
                pwd = pwd.Md532();
                if (string.Equals(pwd, ServiceLocator.ProfileService.Read(name))) {
                    _currentName = name;
                    _currentPwd = pwd;
                    return true;
                }
            }

            return false;
        }

        /// <summary>
        ///     登出
        /// </summary>
        /// <returns></returns>
        public bool SignOut() {
            Logger.Info("SignOut");
            _currentProfilId = 0;
            _currentProfile = null;
            _currentName = string.Empty;
            _currentPwd = string.Empty;
            _signedIn = false;
            return true;
        }


        /// <summary>
        ///     当前场景
        /// </summary>
        /// <returns></returns>
        public Scene GetCurrentScene() {
            return _currentScene;
        }

        /// <summary>
        ///     当前玩家
        /// </summary>
        /// <returns></returns>
        public CurrentPlayer GetCurrentPlayer() {
            return _currentPlayer;
        }

        private void InitializeInterfaces() {
            _interfaces[InterfaceType.Start] = new StartInterface();
            _interfaces[InterfaceType.SignIn] = new SignInInterface();
            _interfaces[InterfaceType.SignUp] = new SignUpInterface();
            _interfaces[InterfaceType.Profile] = new ProfileInterface();
            _interfaces[InterfaceType.Create] = new CreateInterface();
            _interfaces[InterfaceType.Main] = new MainInterface();
            _interfaces[InterfaceType.Fight] = new FightInterface();
            _interfaces[InterfaceType.Loading] = new LoadingInterface();
            _interfaces[InterfaceType.Monolog] = new MonologInterface();
        }

    }

    public static class Externtions {

        /// <summary>
        /// </summary>
        /// <param name="engine"></param>
        public static void Start(this IClientEngine engine) {
            if (Global.Profile) {
                engine.Goto(InterfaceType.Start);
            } else {
                engine.SignUp(Global.DevelopName, Global.DevelopPwd.Md532());
                engine.SignIn(Global.DevelopName, Global.DevelopPwd.Md532());
                if (!engine.LoadProfile(Global.DevelopProfileId)) {
                    engine.SaveProfile();
                    engine.LoadProfile(Global.DevelopProfileId);
                }

                ServiceLocator.ClientEngine.GetCurrentPlayer().At = new Point(2000, 1500);
                engine.Goto(InterfaceType.Main);
            }
        }

    }

}