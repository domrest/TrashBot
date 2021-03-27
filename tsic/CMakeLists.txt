cmake_minimum_required(VERSION 3.10)

# set the project name
project(Tsic)

# add the executable
add_executable(Tsic
        TempDetector.cpp
        tsic.cpp
        main.cpp
        pigpiomgr.h
        )

target_link_libraries(Tsic
        pigpio)
