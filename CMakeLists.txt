cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME RussianRoulette)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSION OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable("${PROJECT_NAME}" RussianRoulette.cpp Functions.cpp Functions.h)

file(COPY "GameResults.txt" DESTINATION "/")
