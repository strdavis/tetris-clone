# If you have installed SDL2_GPU at a non-standard path,
# save the path to environment variable "SDL2_GPU_ROOT".
# find_path and find_library will include this path
# in the searches.

find_path(
    SDL2_GPU_INCLUDE_DIRS
    NAMES
    SDL_gpu.h 
	PATH_SUFFIXES
    include
    include/SDL2
)

if(CMAKE_SIZEOF_VOID_P EQUAL 4)
   set(SDL2_GPU_LIBRARY_PATH_SUFFIXES SDL2_gpu/debug/x86)
else()
   set(SDL2_GPU_LIBRARY_PATH_SUFFIXES SDL2_gpu/debug/x64)
endif()

find_library(
    SDL2_GPU_LIBRARIES
    NAMES
    SDL2_gpu
    libSDL2_gpu
    PATH_SUFFIXES
    ${SDL2_GPU_LIBRARY_PATH_SUFFIXES}
)

get_filename_component(SDL2_GPU_LIBDIR ${SDL2_GPU_LIBRARIES} DIRECTORY)

include(${CMAKE_CURRENT_LIST_DIR}/FindPackageHandleStandardArgs.cmake)

find_package_handle_standard_args(
    SDL2_GPU
	REQUIRED_VARS
    SDL2_GPU_INCLUDE_DIRS
    SDL2_GPU_LIBDIR
    SDL2_GPU_LIBRARIES
)
					  
mark_as_advanced(SDL2_GPU_INCLUDE_DIRS SDL2_GPU_LIBDIR SDL2_GPU_LIBRARIES)