cmake_minimum_required(VERSION 3.10)
project(cv_work3)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(cv_work3 main.cpp)

target_link_libraries(cv_work3 ${OpenCV_LIBS})