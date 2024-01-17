cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME Russian Roulette)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSION OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable("${PROJECT_NAME}" Russian Roulette.cpp)

file(COPY "GameResults" DESTINATION "/")
