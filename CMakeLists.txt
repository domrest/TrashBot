cmake_minimum_required(VERSION 3.10)

# set the project name
project(Trashbot)

file(GLOB INCLUDE CONFIGURE_DEPENDS
        "include/messaging/*.h"
        "include/messaging/*.hpp"
        "include/GPIO/*.h")
file(GLOB CPP CONFIGURE_DEPENDS "lib/*.cpp")


# add the executable
add_executable(Trashbot
        ${CPP}
        ${INCLUDE}
        )

target_link_libraries(Trashbot
        pigpio
        crypto
        boost_iostreams
        boost_filesystem
        pthread
        boost_thread
        boost_system
        ssl
        )
