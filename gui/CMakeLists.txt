cmake_minimum_required(VERSION 3.7.0)

project(Dashboard VERSION 1.0.0 LANGUAGES CXX C)
set(CMAKE_PREFIX_PATH "/usr/lib/qt5/bin")
set(QT5DIR "$/usr")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Threads REQUIRED)
add_executable(Dashboard mainwindow.cpp main.cpp)


target_link_libraries(Dashboard Qt5::Widgets)
target_link_libraries(Dashboard qwt-qt5)
target_link_libraries(Dashboard Threads::Threads)

install(TARGETS Dashboard DESTINATION bin )
