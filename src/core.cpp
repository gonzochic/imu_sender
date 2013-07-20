//
// Copyright (C) 2013
// Roman Schiefer <roman.schiefer@gmail.com>
//
// Date:       2013/07/19
//

#include "core.hpp"

#include <chrono>
#include <iostream>
#include <functional>

#include "executor.hpp"

using imu_sender::Core;

Core::Core() :
    m_sensor()
{
    std::cout << "C'tor core" << std::endl;
}

Core::~Core()
{
    std::cout << "D'tor core" << std::endl;
}

void Core::run()
{
    imu_sender::Executor executor2(std::bind(&Core::updateSlow, this), 1000);
    executor2.startExecutor();

    std::chrono::milliseconds duration(100);
    int i(0);

    while (true) {
        std::this_thread::sleep_for(duration);
        i++;
    }
   
    executor2.stopExecutor();
}

void Core::update()
{
    
    std::cout << "Update called... " << std::endl;
}


void Core::updateSlow()
{
    std::cout << "Update slow called... " << std::endl;
}
