SET(imu_sender_sources
  core.cpp
  executor.cpp
  main.cpp
)

SET(gpio_sources
  MPU6050.cpp
  I2Cdev.cpp
)

SET (imu_sender_headers
)
ADD_EXECUTABLE(imu_sender
  ${imu_sender_sources}
  ${imu_sender_headers}
  ${gpio_sources}
)


ADD_DEPENDENCIES(imu_sender includes)

INCLUDE_DIRECTORIES(
  ${imu_sender_SOURCE_DIR}/incl
)

TARGET_LINK_LIBRARIES(imu_sender
  ${CMAKE_THREAD_LIBS_INIT}
)





