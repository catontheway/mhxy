// FileName:  ProfileList.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180201 17:45
// Description:   

using System.Collections.Generic;

namespace mhxy.Resource.Profiles {


    /// <summary>
    /// 
    /// </summary>
    public class ProfileList {

        public ProfileList() {
            ProfileBreifs = new List<ProfileBreif>();
        }

        /// <summary>
        /// 
        /// </summary>
        public int Count => ProfileBreifs.Count;

        /// <summary>
        /// ProfileBreif列表
        /// </summary>
        public List<ProfileBreif> ProfileBreifs { get; set; }

    }

}