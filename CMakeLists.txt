cmake_minimum_required(VERSION 3.0.0)
project(edge-detection VERSION 0.0.0)

find_package(OpenCV REQUIRED)

message(STATUS "OpenCV library status:")
message(STATUS "--version: ${OpenCV_VERSION}")
message(STATUS "--libraries: ${OpenCV_LIBS}")
message(STATUS "--include path: ${OpenCV_INCLUDE_DIRS}")
include_directories(${OpenCV_INCLUDE_DIRS})

set(LIBS ${OpenCV_LIBS})

add_executable(edge-detection main.cpp edge.cpp edge.h util.cpp util.h)
target_link_libraries(edge-detection ${LIBS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
