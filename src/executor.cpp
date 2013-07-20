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
      m_duration(duration * 1000)
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
    while (m_runExecutor) {

        const auto start  = std::chrono::high_resolution_clock::now();
        m_updateFunction();
        const auto stop  = std::chrono::high_resolution_clock::now();

        std::this_thread::sleep_for(m_duration - std::chrono::duration_cast<std::chrono::microseconds>(stop-start));
        const auto endOfUpdate = std::chrono::high_resolution_clock::now() - start;

        std::cout << "Update time : "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(endOfUpdate).count()
                  << std::endl;
    }
}


void Executor::stopExecutor()
{
    if (m_runExecutor) {
        m_runExecutor = false;
        m_thread.join();
    }
}
