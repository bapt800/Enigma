cmake_minimum_required(VERSION 3.5)

project(Enigma_test LANGUAGES CXX)

enable_testing()

SET(CMAKE_CXX_STANDARD 11)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Gui REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Gui REQUIRED)

include_directories(catch2)
include_directories(../Enigma_lib)

set(PROJECT_SOURCES
        main.cpp
        tst_core.cpp
        catch2/catch.hpp
        ../Enigma_lib/Enigma.cpp
        ../Enigma_lib/Enigma.hpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_link_libraries(Enigma_test PRIVATE Qt${QT_VERSION_MAJOR}::Gui)

if (DEFINED ENV{CATCH_INCLUDE_DIR})
    set(CATCH_INCLUDE_DIR $ENV{CATCH_INCLUDE_DIR})
else ()
    set(CATCH_INCLUDE_DIR "") # set by Qt Creator wizard
endif ()
if (CATCH_INCLUDE_DIR STREQUAL "")
    message("CATCH_INCLUDE_DIR is not set, assuming Catch2 can be found automatically in your system")
elseif (EXISTS ${CATCH_INCLUDE_DIR})
    include_directories(${CATCH_INCLUDE_DIR})
endif ()
