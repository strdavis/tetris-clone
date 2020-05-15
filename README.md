# tetris-clone

A Tetris implementation for OSX written in C++ with SDL 2.0 and SDL_gpu.
<br />
Written as part of a larger project to create an engine for 2D games.
<br /><br />

![Gameplay Demo](demo/tetris-gameplay.gif)
<br /><br />


## To build. . . 

Install SDL 2.0:
```
brew install sdl2
```
<br />

Install [SDL_gpu](https://github.com/grimfang4/sdl-gpu).
<br /><br />

Install the XCode command-line developer tools:
```
xcode-select --install
```
<br />

Then build from the base directory of this repository:
```
xcodebuild -project tetris.xcodeproj
```
<br />

And find the .app bundle in. . . 
```
build/Release/
```
<br /><br />

This software is released under the MIT license.

Copyright © 2020 Spencer Davis
