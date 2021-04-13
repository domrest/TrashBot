cmake_minimum_required(VERSION 3.10)

# set the project name
project(Trashbot)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "/usr/lib/qt5/bin")
set(QT5DIR "$/usr")

file(GLOB INCLUDE CONFIGURE_DEPENDS
        "include/messaging/*.h"
        "include/messaging/*.hpp"
        "include/GPIO/*.h"
        "include/GUI/*.h")

file(GLOB CPP CONFIGURE_DEPENDS "lib/*.cpp")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Threads REQUIRED)

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
        Qt5::Widgets
        qwt-qt5
        Threads::Threads
        )