//
// Copyright (C) 2013
// Roman Schiefer <roman.schiefer@gmail.com>
//
// Date:       2013/07/19
//

#ifndef IMU_SENDER_CORE_HPP
#define IMU_SENDER_CORE_HPP

#include <iostream>

namespace imu_sender {

    class Core
    {
    public:
        Core();
        ~Core();
        void run();

        void update();
        void updateSlow();
    private:
    };

} // namespace imu_sender

#endif // IMU_SENDER_CORE_HPP
