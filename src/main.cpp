//
// Copyright (C) 2013
// Roman Schiefer <roman.schiefer@gmail.com>
//
// Date:       2013/07/19
//

#include <iostream>

#include "core.hpp"

int main() {
	std::cout << "Hello world" << std::endl;

    imu_sender::Core core;
    core.run();
}
