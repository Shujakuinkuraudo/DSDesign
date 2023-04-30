cmake_minimum_required(VERSION 3.24)
project(DataStruct)

set(CMAKE_CXX_STANDARD 17)
include(CTest)
enable_testing()

set(SOURCES main.cpp )
add_executable(${PROJECT_NAME} ${SOURCES} )
target_include_directories(${PROJECT_NAME} PRIVATE  include/)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
