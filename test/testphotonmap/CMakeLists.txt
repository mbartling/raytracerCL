file(GLOB SRCS *.cpp)

add_executable(testphotonmap ${SRCS})

target_link_libraries(testphotonmap
    libgtest
    libgmock
)

install(TARGETS testphotonmap DESTINATION bin)
