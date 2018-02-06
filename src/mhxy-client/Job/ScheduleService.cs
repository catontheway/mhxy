// FileName:  ScheduleService.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180205 14:15
// Description:   

#region

using System;
using FluentScheduler;

#endregion

namespace mhxy.Job {

    /// <summary>
    /// </summary>
    public class ScheduleService : IScheduleService {

        /// <summary>
        ///     Adds a job schedule to the job manager.
        /// </summary>
        /// <param name="job">Job to run.</param>
        /// <param name="schedule">Job schedule to add.</param>
        public void AddJob(Action job, Action<Schedule> schedule) {
            JobManager.AddJob(job, schedule);
        }

    }

}