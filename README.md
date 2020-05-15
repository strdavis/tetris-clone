# tetris-clone

A Tetris implementation for OSX written in C++ with SDL 2.0 and SDL_gpu.
<br />
Written as part of a larger project to create an engine for 2D games.
<br /><br />

![Gameplay Demo](demo/tetris-gameplay.gif)
<br /><br />


## To build. . . 

Download the [SDL 2.0 runtime binaries](https://www.libsdl.org/download-2.0.php). 
<br />
Copy the .framework to. . .
```
/Library/Frameworks
```
<br />

Download the [SDL_gpu repository](https://github.com/grimfang4/sdl-gpu). From its root directory, build it:
```
cmake -G "Unix Makefiles"
make
```
Find the .framework in. . .
```
SDL_gpu/lib
```
. . . and copy it to. . .
```
/Library/Frameworks
```
<br />


We need to let SDL_gpu know where to find the SDL 2.0 headers. In the .framework you just copied, open the file. . .
```
Versions/A/Headers/SDL_gpu.h
```
. . . and change the following lines. . .
```
<Line 4>: #include "SDL.h"
<Line 9>: #include "begin_code.h"
<Line 2053>: #include "close_code.h"
```
. . . to. . .
```
<Line 4>: #include "SDL2/SDL.h"
<Line 9>: #include "SDL2/begin_code.h"
<Line 2053>: #include "SDL2/close_code.h"
```
<br />


Now we're ready to build. Install the XCode command-line developer tools:
```
xcode-select --install
```
Then build from the root directory of this repository:
```
xcodebuild -project tetris.xcodeproj
```
And find the .app bundle in. . . 
```
build/Release/
```
<br /><br />

This software is released under the MIT License.

Copyright © 2020 Spencer Davis
