// FileName:  ClientEngine.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180201 12:40
// Description:   

using System.Collections.Generic;
using mhxy.Client.UI;
using mhxy.Common;
using mhxy.Resource.Profiles;
using mhxy.Utils;

namespace mhxy.Client {


    /// <summary>
    /// 
    /// </summary>
    public class ClientEngine : ServiceBase, IClientEngine {

        private bool _signedIn;
        // private bool _profilLoaded = true;
        private string _currentName;
        private string _currentPwd;
        private int _currentProfilId;
        private Profile _currentProfile = new Profile { InitCreate = true };
        private InterfaceBase _currentInterface;

        public ClientEngine() {
            InitializeInterfaces();
        }

        /// <summary>
        /// 前往某个界面
        /// </summary>
        /// <param name="interType"></param>
        public void Goto(InterfaceType interType) {
            _currentInterface?.StopDraw();
            _currentInterface = _interfaces[interType];
            _currentInterface?.StartDraw();
        }

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public bool SaveProfile() {
            _currentProfile.InitCreate= false;
            return ServiceLocator.ProfileService.SaveProfile(_currentName, _currentPwd, _currentProfilId, _currentProfile);
        }

        public bool LoadProfile(int id) {
            if (ServiceLocator.ProfileService.TryReadProfile(_currentName, _currentPwd, id, out Profile profile)) {
                _currentProfilId = id;
                _currentProfile = profile;
                //_profilLoaded = true;
                return true;
            }
            return false;
        }

        /// <summary>
        /// 注册
        /// </summary>
        /// <param name="name"></param>
        /// <param name="pwd"></param>
        /// <returns></returns>
        public bool SignUp(string name, string pwd) {
            return !ServiceLocator.ProfileService.Has(name) && ServiceLocator.ProfileService.Create(name, pwd.Md532());
        }

        /// <summary>
        /// 登录
        /// </summary>
        /// <param name="name"></param>
        /// <param name="pwd"></param>
        /// <returns></returns>
        public bool SignIn(string name, string pwd) {
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
        /// 登出
        /// </summary>
        /// <returns></returns>
        public bool SignOut() {
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

        private readonly Dictionary<InterfaceType, InterfaceBase> _interfaces = new Dictionary<InterfaceType, InterfaceBase>();

    }

    public static class Externtions {

        /// <summary>
        /// 
        /// </summary>
        /// <param name="engine"></param>
        public static void Start(this IClientEngine engine) {
            if (Environment.Profile) {
                engine.Goto(InterfaceType.Start);
            } else {
                engine.SignUp(Environment.DevelopName, Environment.DevelopPwd.Md532());
                engine.SignIn(Environment.DevelopName, Environment.DevelopPwd.Md532());
                if (!engine.LoadProfile(Environment.DevelopProfileId)) {
                    engine.SaveProfile();
                    engine.LoadProfile(Environment.DevelopProfileId);
                }
                engine.Goto(InterfaceType.Main);
            }
        }
    }
}