// FileName:  ClientEngine.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180202 08:53
// Description:   

#region

using System.Collections.Generic;
using mhxy.Client.Interfaces;
using mhxy.Common;
using mhxy.Core;
using mhxy.Resource.Profiles;
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

        private bool _signedIn;

        // private bool _profilLoaded = true;
        private string _currentName;
        private string _currentPwd;
        private int _currentProfilId;
        private Profile _currentProfile = new Profile { InitCreate = true };
        private InterfaceBase _currentInterface;
        private readonly Scene _currentScene = new Scene();

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
                _currentProfilId = id;
                _currentProfile = profile;
                _currentScene.MapId = _currentProfile.MapId;
                _currentScene.PlayerX = _currentProfile.PlayerX;
                _currentScene.PlayerY = _currentProfile.PlayerY;
                //_profilLoaded = true;
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
            //_profilLoaded = false;
            _currentName = string.Empty;
            _currentPwd = string.Empty;
            _signedIn = false;
            return true;
        }

        private void InitializeInterfaces() {
            _interfaces[InterfaceType.Start] = new StartInterface();
            _interfaces[InterfaceType.SignIn] = new SignInInterface();
            _interfaces[InterfaceType.SignUp] = new SignUpInterface();
            _interfaces[InterfaceType.Profile] = new ProfileInterface();
            _interfaces[InterfaceType.Create] = new CreateInterface();
            _interfaces[InterfaceType.Main] = new MainInterface();
        }

        public Scene GetCurrentScene() {
            return _currentScene;
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
                engine.Goto(InterfaceType.Main);
            }
        }

    }

}