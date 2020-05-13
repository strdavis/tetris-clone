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


#include "game-state.h"

#include <iostream>

#include "data-transfer-types.h"
#include "image-bank.h"
#include "game-element.h"
#include "sprite.h"
#include "background.h"
#include "title.h"
#include "instructions.h"
#include "next-block-display.h"
#include "level-display.h"
#include "high-score-display.h"
#include "score-display.h"
#include "line-count-display.h"
#include "block-count-display.h"
#include "grid.h"

using std::vector;
using std::shared_ptr;
using std::make_shared;


GameState::GameState(shared_ptr <ImageBank> imageBank)
    : imageBank         (imageBank),
      runStatus         (true),
      pauseStatus       (false),
      fullscreen        (false),
      background        (make_shared <Background>       (imageBank)),
      title             (make_shared <Title>            (imageBank)),
      instructions      (make_shared <Instructions>     (imageBank)),
      nextBlockDisplay  (make_shared <NextBlockDisplay> (imageBank)),
      levelDisplay      (make_shared <LevelDisplay>     (imageBank)),
      highScoreDisplay  (make_shared <HighScoreDisplay> (imageBank)),
      scoreDisplay      (make_shared <ScoreDisplay>     (imageBank)),
      lineCountDisplay  (make_shared <LineCountDisplay> (imageBank)),
      blockCountDisplay (make_shared <BlockCountDisplay>(imageBank)),
      grid              (make_shared <Grid>             (imageBank))
{
    activeElements.push_back(background);
    activeElements.push_back(title);
    activeElements.push_back(instructions);
    activeElements.push_back(nextBlockDisplay);
    activeElements.push_back(levelDisplay);
    activeElements.push_back(highScoreDisplay);
    activeElements.push_back(scoreDisplay);
    activeElements.push_back(lineCountDisplay);
    activeElements.push_back(blockCountDisplay);
    activeElements.push_back(grid);
}


void GameState::update(InputData inputData)
{
    checkForQuit(inputData);
    
    checkForReset(inputData);
    
    checkForPause(inputData);
    
    checkForFullscreenToggle(inputData);
    
    if (!pauseStatus)
    {
        // Update all game elements.
        grid->update(inputData);
        
        levelDisplay->update(grid->getLevel());

        nextBlockDisplay->update(grid->getNextBlockIdentifier());
        
        highScoreDisplay->update(grid->getHighscore());
        
        scoreDisplay->update(grid->getScore());
        
        lineCountDisplay->update(grid->getLineCount());
        
        blockCountDisplay->update(grid->getBlockCounts());
    }
}


void GameState::checkForQuit(InputData inputData)
{
    if (inputData.quit || inputData.keyStates.q.pressed)
    {
        runStatus = false;
    }
}


void GameState::checkForReset(InputData inputData)
{
    if (inputData.keyStates.r.pressed)
    {
        grid->reset();
        pauseStatus = false;
    }
}


void GameState::checkForPause(InputData inputData)
{
    if (inputData.keyStates.p.pressed)
    {
        if (pauseStatus == true)
        {
            pauseStatus = false;
        }
        else
        {
            pauseStatus = true;
        }
        
        grid->toggleGridCover();
    }
}


void GameState::checkForFullscreenToggle(InputData inputData)
{
    if (inputData.keyStates.f.pressed)
    {
        if (fullscreen == true)
        {
            fullscreen = false;
        }
        else
        {
            fullscreen = true;
        }
    }
}


vector <shared_ptr <Sprite>> GameState::getSprites()
{
    vector <shared_ptr <Sprite>> sprites;
    
    for (auto element : activeElements)
    {
        auto elementSprites = element->getSprites();
        
        // Append element sprites to return vector
        sprites.insert(end(sprites), begin(elementSprites), end(elementSprites));
    }

    return sprites;
}


WindowFlags GameState::getWindowFlags()
{
    WindowFlags windowFlags;
    
    windowFlags.fullscreen = fullscreen;
    
    return windowFlags;
}


SaveData GameState::getSaveData()
{
    SaveData saveData;
    
    saveData.highScore = grid->getHighscore();
    
    return saveData;
}


bool GameState::getRunStatus()
{
    return runStatus;
}


bool GameState::getPauseStatus()
{
    return pauseStatus;
}


void GameState::setRunStatus(bool status)
{
    runStatus = status;
}


void GameState::setPauseStatus(bool status)
{
    pauseStatus = status;
}


void GameState::setLoadedSaveData(SaveData saveData)
{
    grid->setHighScore(saveData.highScore);
}

