cmake_minimum_required(VERSION 3.1.3)

find_package(Threads REQUIRED)

enable_testing()
find_package(GTest REQUIRED)

file(GLOB SRCS *.cpp)

add_executable(testphotonmap ${SRCS})

target_link_libraries(testphotonmap
    ${GTEST_BOTH_LIBRARIES}
)
target_link_libraries(testphotonmap ${CMAKE_THREAD_LIBS_INIT})

add_test(AllPhotonTests testphotonmap)
#install(TARGETS testphotonmap DESTINATION bin)
GTEST_ADD_TESTS(PhotonTests ${SRCS})