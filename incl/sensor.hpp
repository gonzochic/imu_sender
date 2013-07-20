//
// Copyright (C) 2013
// Roman Schiefer <roman.schiefer@gmail.com>
//
// Date:       2013/07/20
//

#ifndef IMU_SENSOR_SENSOR_HPP
#define IMU_SENSOR_SENSOR_HPP

#include <memory>
#include <mutex>

#include "executor.hpp"
#include "MPU6050.h"

namespace imu_sender {

    struct ImuData
    {
        int16_t x;
        int16_t y;
        int16_t z;
    };

    class Sensor
    {
    public:
        Sensor();
        ~Sensor();

        void loadData();

        const ImuData& getSensorData(); 
        

    private:

        std::mutex m_imuDataLock;
        std::shared_ptr<MPU6050> m_mpu;
        ImuData m_imuData;
        ImuData m_dataCache;

        Executor m_mpuExecutor;

    };
    
} // namespace imu_sender

#endif // IMU_SENSOR_SENSOR_HPP
