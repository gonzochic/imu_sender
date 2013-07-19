SET(imu_sender_sources
  main.cpp
)
SET (imu_sender_headers
)
ADD_EXECUTABLE(imu_sender
  ${imu_sender_sources}
  ${imu_sender_headers}
)


ADD_DEPENDENCIES(imu_sender includes)

INCLUDE_DIRECTORIES(
  ${imu_sender_SOURCE_DIR}/incl
)

TARGET_LINK_LIBRARIES(imu_sender
)





