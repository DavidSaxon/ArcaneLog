cmake_minimum_required(VERSION 2.6)
project(ArcaneLog)

set(LIB_SRC
    src/cpp/arcanelog/AbstractOutput.cpp
    src/cpp/arcanelog/Input.cpp
    src/cpp/arcanelog/LogHandler.cpp
    src/cpp/arcanelog/Stream.cpp
    src/cpp/arcanelog/outputs/FileOutput.cpp
    src/cpp/arcanelog/outputs/StdOutput.cpp
)

set(SHARED_SRC
    src/cpp/arcanelog/Shared.cpp
)

set(TESTS_SUITES
    tests/cpp/TestsMain.cpp

    tests/cpp/Logging_TestSuite.cpp
)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/linux_x86)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/linux_x86)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/linux_x86)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++0x -Wall -Wno-varargs -fPIC")

include_directories(
    ${INCLUDE_DIRECTORIES}
    /home/david/Dropbox/Development/ArcaneCore/ArcaneCore/src/cpp
    src/cpp/
    tests/cpp/
)

link_directories(
    ${LINK_DIRECTORIES}
    /home/david/Dropbox/Development/ArcaneCore/ArcaneCore/build/linux_x86
    ${CMAKE_BINARY_DIR}/build/linux_x86
)

add_library(arcanelog STATIC ${LIB_SRC})

target_link_libraries(arcanelog
    arcanecore_base
    arcanecore_io
)

add_library(arcanelog_shared SHARED ${SHARED_SRC})

target_link_libraries(arcanelog_shared
    arcanecore_base
    arcanecore_io
    arcanelog
)

add_executable(tests ${TESTS_SUITES})

target_link_libraries(tests
    arcanecore_test
    arcanecore_base
    arcanecore_io
    arcanelog
)
