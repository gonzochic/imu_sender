CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT (imu_sender C CXX)

IF (NOT DEFINED CMAKE_MODULE_PATH)
  SET(CMAKE_MODULE_PATH "/home/roman/development/cmake_modules")
ENDIF (NOT DEFINED CMAKE_MODULE_PATH)


SET(imu_sender_version   1)
SET(imu_sender_revision  0)
SET(imu_sender_patch     0)

SET(imu_sender_release
        "${imu_sender_version}.${imu_sender_revision}.${imu_sender_patch}")

SET(libimusender_soname
  "${imu_sender_version}")

SET(libimusender_version
  "${imu_sender_version}.${imu_sender_revision}.0")

FILE(WRITE incl/version.hpp
        "#ifndef IMU_SENDER_VERSION_HPP\n#define IMU_SENDER_VERSION_HPP\n\n"
        "#define IMU_SENDER_VERSION \"${imu_sender_release}\"\n\n"
        "#endif // IMU_SENDER_VERSION_HPP\n"
)

SET(CMAKE_CXX_FLAGS "-Wall -O2 -std=c++11 -pthread")
SET(PROJECT_VERSION ${imu_sender_release})

SET_DIRECTORY_PROPERTIES(PROPERTIES
	ADDITIONAL_MAKE_CLEAN_FILES "${clean_targets}"
)
######################################################################
# common

ADD_SUBDIRECTORY (src)
SET(CPACK_Boost_VERSION_REQUIRED 1.40)
FIND_PACKAGE(Boost ${CPACK_Boost_VERSION_REQUIRED} COMPONENTS system regex REQUIRED)



FIND_PACKAGE(Threads REQUIRED)

# CTest config
# ENABLE_TESTING()

IF (NOT TEST_OUTPUT_FORMAT)
  SET(TEST_OUTPUT_FORMAT "xml")
  MESSAGE("setting output format of tests to ${TEST_OUTPUT_FORMAT}.. consider using: \"$ cmake -DTEST_OUTPUT_FORMAT=[plain|xml]\"")
ENDIF (NOT TEST_OUTPUT_FORMAT)

#ADD_TEST(imu_sender ./ut/ut.imu_sender_core ${TEST_OUTPUT_FORMAT} )

#INCLUDE(CTest)

