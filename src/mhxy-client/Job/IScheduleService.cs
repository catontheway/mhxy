// FileName:  IScheduleService.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180205 14:15
// Description:   

#region

using System;
using FluentScheduler;
using mhxy.Common;

#endregion

namespace mhxy.Job {

    public interface IScheduleService : IService {

        /// <summary>
        ///     Adds a job schedule to the job manager.
        /// </summary>
        /// <param name="job">Job to run.</param>
        /// <param name="schedule">Job schedule to add.</param>
        void AddJob(Action job, Action<Schedule> schedule);

    }

}