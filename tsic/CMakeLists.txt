cmake_minimum_required(VERSION 3.10)

# set the project name
project(Tsic)

# add the executable
add_executable(Tsic
        tsic.cpp
        main.cpp
        )

link_libraries(Tsic
        pigpio)
