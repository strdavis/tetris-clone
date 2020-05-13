/*
* MIT License
*
* Copyright (c) 2020 Spencer Davis
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/


#pragma once

#include <memory>
#include <string>

struct ImageBank;

class FileManager;
class InputCollector;
class GameState;
class DisplayModule;


// Top-level node of game engine.
// Initializes engine components.
// Controls game loop.
class Engine
{
public:
    Engine(std::string appSupportDirectory);
    
    void runGameLoop();
    
private:
    void limitFPS(int fps, int frameStartTime);
    
    std::string appSupportDirectory;
    std::unique_ptr <FileManager> fileManager;
    std::unique_ptr <InputCollector> inputCollector;
    std::shared_ptr <DisplayModule> displayModule;
    std::shared_ptr <ImageBank> imageBank;
    std::shared_ptr <GameState> gameState;
};
