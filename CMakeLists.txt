cmake_minimum_required(VERSION 2.8)
project(rougelike)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -O0")

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(SOURCE_FILES Game.cpp main.cpp Player.cpp ResourceManager.cpp)
include_directories("${PROJECT_SOURCE_DIR}")

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED network audio graphics window system)
find_package (Threads)

if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

# target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})
# target_link_libraries(${PROJECT_NAME} dl) # For ldl

