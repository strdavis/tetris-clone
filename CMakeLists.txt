# Specify minimum cmake version.
cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

# Specify project name.
project(tetris_clone)

# Specify C++ version.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Ensure CMake uses the new policy
# for checking <package name>_ROOT
# variables during searches.
# See: https://cmake.org/cmake/help/latest/policy/CMP0074.html
cmake_policy(SET CMP0074 NEW)

# Find packages.
#
# If the packages have been installed at non-standard locations,
# specify their paths in the following environment variables:
#
# SDL2_ROOT
# SDL2_GPU_ROOT
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
find_package(SDL2 REQUIRED)
find_package(SDL2_gpu REQUIRED)

# Yields:
# SDL2_INCLUDE_DIRS
# SDL2_LIBDIR
# SDL2_LIBRARIES
# SDL2_GPU_INCLUDE_DIRS
# SDL2_LIBDIR
# SDL2_GPU_LIBRARIES

# Obtain source files.
set(TETRIS_APP_DIR ${CMAKE_SOURCE_DIR}/src/app)
set(TETRIS_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/src/include)
set(TETRIS_LIB_DIRS ${CMAKE_SOURCE_DIR}/src/lib)

# Always use "bin" directory for output (rather than Debug/Release).
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_BINARY_DIR}/bin)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_BINARY_DIR}/bin)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_BINARY_DIR}/bin)
endforeach(OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES)

# Create executables.
add_executable(tetris_clone
    ${TETRIS_APP_DIR}/tetris-clone.cpp
    ${TETRIS_LIB_DIRS}/engine/display-module.cpp
    ${TETRIS_LIB_DIRS}/engine/engine.cpp
    ${TETRIS_LIB_DIRS}/engine/file-manager.cpp
    ${TETRIS_LIB_DIRS}/engine/game-element.cpp
    ${TETRIS_LIB_DIRS}/engine/game-state.cpp
    ${TETRIS_LIB_DIRS}/engine/image-bank.cpp
    ${TETRIS_LIB_DIRS}/engine/input-collector.cpp
    ${TETRIS_LIB_DIRS}/engine/random-number-generator.cpp
    ${TETRIS_LIB_DIRS}/engine/rendering-unit.cpp
    ${TETRIS_LIB_DIRS}/engine/sdl-initializer.cpp
    ${TETRIS_LIB_DIRS}/engine/sprite.cpp
    ${TETRIS_LIB_DIRS}/engine/window-controller.cpp
    ${TETRIS_LIB_DIRS}/engine/wrapped-gpu-image.cpp
    ${TETRIS_LIB_DIRS}/game-elements/background.cpp
    ${TETRIS_LIB_DIRS}/game-elements/block-count-display.cpp
    ${TETRIS_LIB_DIRS}/game-elements/digital-display.cpp
    ${TETRIS_LIB_DIRS}/game-elements/grid.cpp
    ${TETRIS_LIB_DIRS}/game-elements/high-score-display.cpp
    ${TETRIS_LIB_DIRS}/game-elements/instructions.cpp
    ${TETRIS_LIB_DIRS}/game-elements/level-display.cpp
    ${TETRIS_LIB_DIRS}/game-elements/line-count-display.cpp
    ${TETRIS_LIB_DIRS}/game-elements/next-block-display.cpp
    ${TETRIS_LIB_DIRS}/game-elements/panel.cpp
    ${TETRIS_LIB_DIRS}/game-elements/score-display.cpp
    ${TETRIS_LIB_DIRS}/game-elements/title.cpp
    ${TETRIS_LIB_DIRS}/game-elements/blocks/block.cpp
    ${TETRIS_LIB_DIRS}/game-elements/blocks/i-block.cpp
    ${TETRIS_LIB_DIRS}/game-elements/blocks/j-block.cpp
    ${TETRIS_LIB_DIRS}/game-elements/blocks/l-block.cpp
    ${TETRIS_LIB_DIRS}/game-elements/blocks/o-block.cpp
    ${TETRIS_LIB_DIRS}/game-elements/blocks/s-block.cpp
    ${TETRIS_LIB_DIRS}/game-elements/blocks/t-block.cpp
    ${TETRIS_LIB_DIRS}/game-elements/blocks/z-block.cpp)

target_include_directories(tetris_clone PUBLIC
    ${SDL2_INCLUDE_DIRS}
    ${SDL2_GPU_INCLUDE_DIRS}
    ${TETRIS_INCLUDE_DIRS}/engine
    ${TETRIS_INCLUDE_DIRS}/game-elements
    ${TETRIS_INCLUDE_DIRS}/game-elements/blocks)
    
target_link_libraries(tetris_clone ${SDL2_LIBRARIES} ${SDL2_GPU_LIBRARIES})

# If using Windows, copy libraries to output directory so they can be used by executables.
if(WIN32)
    add_custom_command(
        TARGET tetris_clone
        POST_BUILD COMMAND ${CMAKE_COMMAND} -E
        copy_directory ${SDL2_LIBDIR} ${CMAKE_BINARY_DIR}/bin
    )
    add_custom_command(
        TARGET tetris_clone POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${SDL2_GPU_LIBDIR} ${CMAKE_BINARY_DIR}/bin
    )
endif()






########################################

# # If using Windows, point CMake to the locations of the dependency packages,
# # as specified in paths.cmake.
# include("paths.cmake")
# if(WIN32)
#     if (SDL2_PACKAGE_DIR)
#         list(APPEND CMAKE_PREFIX_PATH ${SDL2_PACKAGE_DIR})
#     endif()
#     if (SDL2_GPU_PACKAGE_DIR)
#         list(APPEND CMAKE_PREFIX_PATH ${SDL2_GPU_PACKAGE_DIR})
#     endif()
# endif()

# # Find SDL2.
# # -> On Windows, CMake will find and use sdl2-config.cmake in the package pointed to above.
# # -> On Mac, CMake will find SDL2 in the default installation directory.
# find_package(SDL2 REQUIRED)

# # Find SDL2_gpu.
# # -> On Windows, we must initialize the path variables manually,
# #    since the SDL2_gpu package lacks a <package>config.cmake file.
# # -> On Mac, CMake will find SDL2_gpu in the default installation directory.
# if(WIN32)
#     set(SDL2_GPU_DIR ${SDL2_GPU_PACKAGE_DIR})
#     if(CMAKE_SIZEOF_VOID_P STREQUAL "4")
#         set(_sdl_gpu_arch_subdir "x86")
#     elseif(CMAKE_SIZEOF_VOID_P STREQUAL "8")
#         set(_sdl_gpu_arch_subdir "x64")
#     else()
#         message("Failed to identify target platform.")
#         return()
#     endif()
#     set(SDL2_GPU_LIB_DIRS ${SDL2_GPU_DIR}/SDL2_gpu/debug/${_sdl_gpu_arch_subdir})
#     set(SDL2_GPU_INCLUDE_DIRS ${SDL2_GPU_DIR}/include)
#     set(SDL2_GPU_LIBRARIES ${SDL2_GPU_LIB_DIRS}/SDL2_gpu.lib)
# else()
#     find_library(SDL2_GPU_LIBRARIES SDL2_gpu REQUIRED)
# endif()

# # Obtain source files.
# set(TETRIS_APP_DIR ${CMAKE_SOURCE_DIR}/src/app)
# set(TETRIS_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/src/include)
# set(TETRIS_LIB_DIRS ${CMAKE_SOURCE_DIR}/src/lib)

# # Always use "bin" directory for output (rather than Debug/Release).
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
#     string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG)
#     set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_BINARY_DIR}/bin)
#     set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_BINARY_DIR}/bin)
#     set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_BINARY_DIR}/bin)
# endforeach(OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES)

# # Create executables.
# add_executable(tetris_clone
#     ${TETRIS_APP_DIR}/tetris-clone.cpp
#     ${TETRIS_LIB_DIRS}/engine/display-module.cpp
#     ${TETRIS_LIB_DIRS}/engine/engine.cpp
#     ${TETRIS_LIB_DIRS}/engine/file-manager.cpp
#     ${TETRIS_LIB_DIRS}/engine/game-element.cpp
#     ${TETRIS_LIB_DIRS}/engine/game-state.cpp
#     ${TETRIS_LIB_DIRS}/engine/image-bank.cpp
#     ${TETRIS_LIB_DIRS}/engine/input-collector.cpp
#     ${TETRIS_LIB_DIRS}/engine/random-number-generator.cpp
#     ${TETRIS_LIB_DIRS}/engine/rendering-unit.cpp
#     ${TETRIS_LIB_DIRS}/engine/sdl-initializer.cpp
#     ${TETRIS_LIB_DIRS}/engine/sprite.cpp
#     ${TETRIS_LIB_DIRS}/engine/window-controller.cpp
#     ${TETRIS_LIB_DIRS}/engine/wrapped-gpu-image.cpp
#     ${TETRIS_LIB_DIRS}/game-elements/background.cpp
#     ${TETRIS_LIB_DIRS}/game-elements/block-count-display.cpp
#     ${TETRIS_LIB_DIRS}/game-elements/digital-display.cpp
#     ${TETRIS_LIB_DIRS}/game-elements/grid.cpp
#     ${TETRIS_LIB_DIRS}/game-elements/high-score-display.cpp
#     ${TETRIS_LIB_DIRS}/game-elements/instructions.cpp
#     ${TETRIS_LIB_DIRS}/game-elements/level-display.cpp
#     ${TETRIS_LIB_DIRS}/game-elements/line-count-display.cpp
#     ${TETRIS_LIB_DIRS}/game-elements/next-block-display.cpp
#     ${TETRIS_LIB_DIRS}/game-elements/panel.cpp
#     ${TETRIS_LIB_DIRS}/game-elements/score-display.cpp
#     ${TETRIS_LIB_DIRS}/game-elements/title.cpp
#     ${TETRIS_LIB_DIRS}/game-elements/blocks/block.cpp
#     ${TETRIS_LIB_DIRS}/game-elements/blocks/i-block.cpp
#     ${TETRIS_LIB_DIRS}/game-elements/blocks/j-block.cpp
#     ${TETRIS_LIB_DIRS}/game-elements/blocks/l-block.cpp
#     ${TETRIS_LIB_DIRS}/game-elements/blocks/o-block.cpp
#     ${TETRIS_LIB_DIRS}/game-elements/blocks/s-block.cpp
#     ${TETRIS_LIB_DIRS}/game-elements/blocks/t-block.cpp
#     ${TETRIS_LIB_DIRS}/game-elements/blocks/z-block.cpp)

# target_include_directories(tetris_clone PUBLIC
#     ${SDL2_INCLUDE_DIRS}
#     ${SDL2_GPU_INCLUDE_DIRS}
#     ${TETRIS_INCLUDE_DIRS}/engine
#     ${TETRIS_INCLUDE_DIRS}/game-elements
#     ${TETRIS_INCLUDE_DIRS}/game-elements/blocks)
    
# target_link_libraries(tetris_clone ${SDL2_LIBRARIES} ${SDL2_GPU_LIBRARIES})

# # If using Windows, copy libraries to output directory so they can be used by executables.
# if(WIN32)
#     add_custom_command(TARGET tetris_clone POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${SDL2_LIBDIR} ${CMAKE_BINARY_DIR}/bin)
#     add_custom_command(TARGET tetris_clone POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${SDL2_GPU_LIB_DIRS} ${CMAKE_BINARY_DIR}/bin)
# endif()


