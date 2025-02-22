cmake_minimum_required(VERSION 3.2)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
                 ${CMAKE_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Cars)

set(SRC_LIST
    Car.hpp
    Car.cpp
    ElectricCar.cpp
    ElectricCar.hpp
    ElectricEngine.cpp
    ElectricEngine.hpp
    HybridCar.cpp
    HybridCar.hpp
    PetrolCar.cpp
    PetrolCar.hpp
    PetrolEngine.cpp
    PetrolEngine.hpp
    Exceptions.hpp
    Gear.hpp
)

add_executable(${PROJECT_NAME} ${SRC_LIST} main.cpp)
target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Werror -Wpedantic -Wextra)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR})
set(TEST_SRC_LIST
    tests/main.cpp
    tests/PetrolCarTests.cpp)

link_libraries(gtest)
add_executable(${PROJECT_NAME}-ut ${TEST_SRC_LIST} ${SRC_LIST})
target_compile_options(${PROJECT_NAME}-ut PUBLIC -Wall -Werror -Wpedantic -Wextra)