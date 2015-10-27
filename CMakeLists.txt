project(eigen_tests CXX C)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

find_package(Eigen3 REQUIRED)

message(status "EIGEN3_INCLUDE_DIRS: ${EIGEN3_INCLUDE_DIRS}")

include_directories(
    ${EIGEN3_INCLUDE_DIR})

add_executable(selfadjoint_eigensolver_test src/selfadjoint_eigensolver_test.cpp)

install(TARGETS selfadjoint_eigensolver_test
    RUNTIME DESTINATION bin)
