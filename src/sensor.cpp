//
// Copyright (C) 2013
// Roman Schiefer <roman.schiefer@gmail.com>
//
// Date:       2013/07/20
//

#include "sensor.hpp"

#include <iostream>

using imu_sender::Sensor;

Sensor::Sensor() :
    m_mpu(new MPU6050()),
    m_imuData(),
    m_mpuExecutor(std::bind(&Sensor::loadData,this), 100)
{
    m_imuData.x = 0;
    m_imuData.y = 0;
    m_imuData.z = 0;

    m_mpuExecutor.startExecutor();
}
Sensor::~Sensor()
{
    m_mpuExecutor.stopExecutor();
}

void Sensor::loadData()
{
    std::cout << "Load data..." << std::endl;
    std::lock_guard<std::mutex> g(m_imuDataLock);
    m_mpu->getAcceleration(&m_imuData.x, &m_imuData.y, &m_imuData.z);
}

const imu_sender::ImuData& Sensor::getSensorData()
{
    std::lock_guard<std::mutex> g(m_imuDataLock);
    m_dataCache.x = m_imuData.x;
    m_dataCache.y = m_imuData.y;
    m_dataCache.z = m_imuData.z;
    
    return m_dataCache;
}

