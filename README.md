# tetris-clone

A Tetris implementation for Windows and Mac. Written in C++ with SDL2 and SDL2_gpu.
<br /><br />
![Gameplay Demo](demo/tetris-gameplay.gif)
<br /><br />

## DEPENDENCIES

The following tools must be installed on your system:
- C++ 17
- [CMake 3.2](https://cmake.org/)
- [SDL2 2.26](https://github.com/libsdl-org/SDL)
- [SDL2_gpu 0.12](https://github.com/grimfang4/sdl-gpu)

To ensure that SDL2 and SDL2_gpu are visible to CMake, follow the steps below:

#### WINDOWS SETUP
1. Download and extract the [SDL2 precompiled binaries](https://github.com/libsdl-org/SDL/releases) (SDL2-[version].zip)
2. Download and extract the [SDL2_gpu precompiled binaries](https://github.com/grimfang4/sdl-gpu/releases) (SDL2_gpu-[version]-msvc.zip)
3. Create environment variable ```SDL2_ROOT``` and set it to the path to the extracted SDL2 directory.
4. Create environment variable ```SDL2_GPU_ROOT``` and set it to the path to extracted SDL2_gpu directory.

#### MAC SETUP
```Note:``` SDL2_gpu requires that SDL2 is installed to default directories; using a package manager to install SDL2 may break this.
1. Build and install SDL2 to default directories, from source.
2. Build and install SDL2_gpu to default directories, from source.

## BUILD AND RUN

In the root directory of the repo:
1. Run the ```build``` script for your platform.
2. Run the ```run``` script for your platform.

## CONTROLS

Press the ```arrow keys``` to move the piece.<br />
Press the ```Z``` key to rotate the piece left.<br />
Press the ```X``` key to rotate the piece right.<br />
Press the ```P``` key to pause.<br />
Press the ```R``` key to restart.<br />
Press the ```F``` key to toggle fullscreen / windowed mode.<br />
Press the ```Q``` key to quit.<br />




