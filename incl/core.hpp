//
// Copyright (C) 2013
// Roman Schiefer <roman.schiefer@gmail.com>
//
// Date:       2013/07/19
//

#ifndef IMU_SENDER_CORE_HPP
#define IMU_SENDER_CORE_HPP

#include <iostream>
#include <mutex>
#include <thread>

namespace imu_sender {

    class Core
    {
    public:
        Core();
        ~Core();
        void updateThread(std::string text);
        void run();

        void update();
        void updateSlow();
    private:
        std::mutex m_guard;
        long m_t1;
        long m_t2;
    
    };

} // namespace imu_sender

#endif // IMU_SENDER_CORE_HPP
