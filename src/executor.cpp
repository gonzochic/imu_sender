//
// Copyright (C) 2013
// Roman Schiefer <roman.schiefer@gmail.com>
//
// Date:       2013/07/19
//

#include "executor.hpp"

#include <iostream>
#include <thread>

using imu_sender::Executor;

Executor::Executor(std::function<void()> functionToCall, const int duration)
    : m_updateFunction(functionToCall),
      m_runExecutor(false),
      m_duration(duration)
{
    std::cout << "start with duration : " << duration << std::endl;
}

Executor::~Executor()
{

}

void Executor::startExecutor()
{
    m_runExecutor = true;
    m_thread = std::thread(&Executor::updateExecutor, this);
    //m_thread.detach();
}

void Executor::updateExecutor()
{
    std::cout << "update every : " << m_duration.count() << std::endl;
    while (m_runExecutor) {

        m_updateFunction();
        std::this_thread::sleep_for(m_duration);
    }
}


void Executor::stopExecutor()
{
    m_runExecutor = false;
    m_thread.join();
}
