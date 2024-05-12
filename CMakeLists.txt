cmake_minimum_required(VERSION 3.11)
project(game_of_life)

# Создание compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Зависимости
set(RAYLIB_VERSION 4.5.0)
find_package(raylib ${RAYLIB_VERSION} QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
            raylib
            DOWNLOAD_EXTRACT_TIMESTAMP OFF
            URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED)
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif()
endif()

add_executable(game_of_life
        src/main.cpp
        src/ApplicationElements.cpp
        src/GameOfLife.cpp
        src/ApplicationLogic.cpp
)

target_link_libraries(${PROJECT_NAME} raylib)

set(GTEST_INSTALL_DIR ${CMAKE_BINARY_DIR}/googletest)
if(NOT EXISTS ${GTEST_INSTALL_DIR})
    message("Google Test not found, cloning from Git...")
    execute_process(COMMAND git clone --branch release-1.11.0 --depth 1 https://github.com/google/googletest.git ${GTEST_INSTALL_DIR})
endif()

include_directories(${GTEST_INSTALL_DIR}/googletest/include)

add_subdirectory(${GTEST_INSTALL_DIR})

add_executable(test tests/main.cpp tests/game_of_life_tests.cpp src/ApplicationLogic.cpp)

target_link_libraries(
    test 
    raylib
    GTest::gtest
    GTest::gmock
    GTest::gtest_main
    GTest::gmock_main
)

add_dependencies(test gtest)

add_custom_command(TARGET test POST_BUILD COMMAND test)