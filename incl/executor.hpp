//
// Copyright (C) 2013
// Roman Schiefer <roman.schiefer@gmail.com>
//
// Date:       2013/07/19
//

#ifndef IMU_SENDER_EXECUTOR_HPP
#define IMU_SENDER_EXECUTOR_HPP

#include <chrono>
#include <functional>
#include <thread>

namespace imu_sender {

    class Executor
    {
    public:
        Executor(std::function<void()> functionToCall, const int duration);
        ~Executor();

        void startExecutor();
        void updateExecutor();
        void stopExecutor();

    private:
        std::thread m_thread;
        std::function<void()> m_updateFunction;
        volatile bool m_runExecutor;
        std::chrono::milliseconds m_duration;

    };

} // namespace imu_sender

#endif // IMU_SENDER_EXECUTOR_HPP
