cmake_minimum_required(VERSION 3.0)

project(advcpp)

SET(CMAKE_CXX_STANDARD 23)
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++23")

# added for MacOS Sonoma + GCC 13.2 installation's linker problems
# selects classic linker to be used, not the new linker
SET(CMAKE_CXX_FLAGS "-Wl,-ld_classic")

add_executable(w1a1 "week1-check-lms-for-introduction-ppt.cpp")
add_executable(w2a1 "week2-app1.cpp")
add_executable(w2a2 "week2-app2.cpp")
add_executable(w3a1 "week3-app1.cpp")
add_executable(w4a1 "week4-app1.cpp")
add_executable(w4a2 "week4-app2.cpp")
add_executable(w4a3 "week4-app3.cpp")
add_executable(w5a1 "week5-app1.cpp")
add_executable(w5a2 "week5-app2.cpp")
add_executable(w5a3 "week5-app3.cpp")
add_executable(w5a4 "week5-app4.cpp")
add_executable(w6a1 "week6-app1.cpp")
add_executable(w6a2 "week6-app2.cpp")
add_executable(w6a3 "week6-app3.cpp")
