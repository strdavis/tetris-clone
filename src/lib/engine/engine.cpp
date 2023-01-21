#include "engine.h"

#include <iostream>

#include "SDL_gpu.h"

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
      imageBank             (make_shared <ImageBank> (appSupportDirectory)),
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
