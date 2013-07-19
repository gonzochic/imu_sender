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
    m_t1(0),
    m_t2(0)
{
    std::cout << "C'tor core" << std::endl;
}

Core::~Core()
{
    std::cout << "D'tor core" << std::endl;
}

void Core::updateThread(std::string text)
{
    while (true) {
        m_guard.lock();

        std::cout << "+!!!" << m_t1 << " " << text << " " << m_t2 << "!!!-" << std::endl;

        m_guard.unlock();

    }
    
}

void Core::run()
{
    
    imu_sender::Executor executor(std::bind(&Core::update, this), 50);
    executor.startExecutor();

    imu_sender::Executor executor2(std::bind(&Core::updateSlow, this), 1000);
    executor2.startExecutor();
    // std::thread first(&Core::updateThread, this, "Thread 1");
    
    // first.join();
    // second.join();
    //updateThread("Heap");
    std::chrono::milliseconds duration(100);

    while (true) {
        std::this_thread::sleep_for(duration);
    }
   
    executor.stopExecutor();
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
