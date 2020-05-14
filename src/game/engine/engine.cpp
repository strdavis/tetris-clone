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


#include "engine.h"

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2_gpu/SDL_gpu.h>

#include "data-transfer-types.h"
#include "file-manager.h"
#include "image-bank.h"
#include "input-collector.h"
#include "game-state.h"
#include "display-module.h"

using std::string;
using std::unique_ptr;
using std::shared_ptr;
using std::make_unique;
using std::make_shared;


Engine::Engine(string appSupportDirectory)
    : appSupportDirectory   (appSupportDirectory),
      fileManager           (make_unique <FileManager> (appSupportDirectory)),
      inputCollector        (make_unique <InputCollector> ()),
      displayModule         (make_shared <DisplayModule> ()),
      imageBank             (make_shared <ImageBank> ()),
      gameState             (make_shared <GameState> (imageBank))

      // Display module must be initialized before image bank.
      // Display module initializes renderer.
      // Renderer checks the compatibility of image files as they are loaded.

{
    gameState->setLoadedSaveData(fileManager->loadSaveData());
}


void Engine::runGameLoop()
{
    int fps = 60;
    int frameStartTime;
    while (gameState->getRunStatus())
    {
        frameStartTime = SDL_GetTicks();
        
        gameState->update(inputCollector->getInput());
            
        displayModule->refresh(gameState->getWindowFlags(), gameState->getSprites());
            
        limitFPS(fps, frameStartTime);
    }
    
    //When game loop terminates. . .
    fileManager->storeSaveData(gameState->getSaveData());
    
    GPU_Quit();
    delete this;
}


void Engine::limitFPS(int fps, int frameStartTime)
{
    int frameDuration = 1000 / fps;
    int frameEndTime;
    int ticksElapsed;
    int ticksRemaining;
    
    frameEndTime = SDL_GetTicks();
    ticksElapsed = frameEndTime - frameStartTime;
    ticksRemaining = frameDuration - ticksElapsed;
    
    if (ticksRemaining > 0)
    {
        SDL_Delay(ticksRemaining);
    }
}
