//
// Copyright (C) 2013
// Roman Schiefer <roman.schiefer@gmail.com>
//
// Date:       2013/07/19
//

#ifndef IMU_SENDER_CORE_HPP
#define IMU_SENDER_CORE_HPP

#include <memory>

#include "MPU6050.h"
#include "sensor.hpp"

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
        Sensor m_sensor;
    };

} // namespace imu_sender

#endif // IMU_SENDER_CORE_HPP
