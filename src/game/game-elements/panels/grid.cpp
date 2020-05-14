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


#include "grid.h"

#include <iostream>

#include <SDL2_gpu/SDL_gpu.h>

#include "random-number-generator.h"
#include "data-transfer-types.h"
#include "image-bank.h"
#include "game-element.h"
#include "sprite.h"
#include "wrapped-gpu-image.h"
#include "i-block.h"
#include "o-block.h"
#include "t-block.h"
#include "j-block.h"
#include "l-block.h"
#include "z-block.h"
#include "s-block.h"

using std::array;
using std::vector;
using std::shared_ptr;
using std::make_shared;

using namespace std;


Grid::Grid(shared_ptr <ImageBank> imageBank)
    : Panel(imageBank),
      level(1),
      score(0),
      highScore(0),
      lineCount(0),
      gameOver(false),
      gridCover(make_shared <Sprite> ()),
      rng(make_shared <RandomNumberGenerator> ())
{
    background->setImage(imageBank->white);
    background->setSize(80, 160);
    
    frame->setImage(imageBank->gridFrame);
    frame->setSize(96, 176);
    
    gridCover->setImage(imageBank->transparent);
    gridCover->setSize(80, 160);
    
    reset();
}


void Grid::update(InputData inputData)
{
    if (gameOver)
    {
        SDL_Delay(2000);
        reset();
    }
    else if (activeBlock->hasReachedBottom)
    {
        copyActiveBlockToGrid();
        
        updateScore(clearLines());
        
        checkForLevelUp();
        
        activateNextBlock();
        
        checkForGameOver();
    }
    
    activeBlock->update(inputData);
}


void Grid::reset()
{
    level = 1;
    score = 0;
    lineCount = 0;
    gameOver = false;
    
    // Reset block counts.
    for (int i = 0; i < 7; i++)
    {
        blockCounts[i] = 0;
    }
    
    // Clear grid array.
    for (int i = 0; i < 22; i++) // Rows
    {
        for (int j = 2; j < 12; j++) // Columns
        {
            gridArray[i][j] = '.';
        }
    }
    
    // Remove grid cover if active.
    if (gridCover->getImage() == imageBank->gridCoverPaused)
    {
        toggleGridCover();
    };
    
    nextBlock = generateRandomBlock();
    activateNextBlock();
}


void Grid::activateNextBlock()
{
    activeBlock = nextBlock;
    nextBlock = generateRandomBlock();
    
    blockCounts[activeBlock->identifier]++;
}


shared_ptr <Block> Grid::generateRandomBlock()
{
    shared_ptr <Block> randomBlock;
    
    int random = rng->getRandomIntInRange(0, 6);
    
    switch (random)
    {
        case 0:
            randomBlock = make_shared <IBlock> (&gridArray, level);
            break;
            
        case 1:
            randomBlock = make_shared <OBlock> (&gridArray, level);
            break;
            
        case 2:
            randomBlock = make_shared <TBlock> (&gridArray, level);
            break;
            
        case 3:
            randomBlock = make_shared <JBlock> (&gridArray, level);
            break;
            
        case 4:
            randomBlock = make_shared <LBlock> (&gridArray, level);
            break;
            
        case 5:
            randomBlock = make_shared <ZBlock> (&gridArray, level);
            break;
            
        case 6:
            randomBlock = make_shared <SBlock> (&gridArray, level);
            break;
    }
    
    return randomBlock;
}


void Grid::copyActiveBlockToGrid()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            vector <vector <char>> orientation = *(activeBlock->orientation);
            
            if (orientation[i][j] != '.')
            {
                int subBlockGridPosX = activeBlock->gridPosX + j;
                int subBlockGridPosY = activeBlock->gridPosY + i;
                
                gridArray[subBlockGridPosY][subBlockGridPosX] = orientation[i][j];
            }
        }
    }
    
    // Short delay before spawning new block;
    SDL_Delay(400);
}


int Grid::clearLines()
{
    int linesCleared = 0;
    
    // For each line. . .
    for (int i = 0; i < 22; i++)
    {
        bool lineComplete = true;
        
        // Check if complete.
        for (int j = 3; j < 12; j++)
        {
            if (gridArray[i][j] == '.')
            {
                lineComplete = false;
            }
        }

        if (lineComplete)
        {
            linesCleared++;
            
            // Clear line.
            for (int j = 2; j < 12; j++)
            {
                gridArray[i][j] = '.';
            }
            
            collapseFromRow(i);
        }
    }
    
    lineCount += linesCleared;
    
    return linesCleared;
}


void Grid::checkForLevelUp()
{
    if (level < 9 && score > (level * level * 5000))
    {
        level++;
    }
}


void Grid::checkForGameOver()
{
    if (!activeBlock->checkValidPosition())
    {
        gameOver = true;
    }
}


void Grid::collapseFromRow(int row)
{
    for (int i = row; i > 0; i--)
    {
        for (int j = 2; j < 12; j++)
        {
            gridArray[i][j] = gridArray[i - 1][j];
        }
    }
}


void Grid::updateScore(int linesCleared)
{
    switch (linesCleared)
    {
        case 1:
            score += level * 100;
            break;
            
        case 2:
            score += level * 250;
            break;
            
        case 3:
            score += level * 750;
            break;
            
        case 4:
            score += level * 3000;
            break;
            
        default:
            break;
    }
    
    if (score > highScore)
    {
        setHighScore(score);
    }
}


vector <shared_ptr <Sprite>> Grid::getSprites()
{
    // Clear sprites vector
    vector <shared_ptr <Sprite>> temp;
    sprites.swap(temp);
    
    sprites.push_back(frame);
    sprites.push_back(background);
    
    vector <shared_ptr <Sprite>> playedBlockSprites = getSpritesForFallenBlocks();
    vector <shared_ptr <Sprite>> activeBlockSprites = getSpritesForActiveBlock();
    
    // Append block sprites to return vector.
    sprites.insert(end(sprites), begin(playedBlockSprites), end(playedBlockSprites));
    sprites.insert(end(sprites), begin(activeBlockSprites), end(activeBlockSprites));
    
    sprites.push_back(gridCover);
    
    return GameElement::getSprites();
}


vector <shared_ptr <Sprite>> Grid::getSpritesForFallenBlocks()
{
    vector <shared_ptr <Sprite>> playedBlockSprites;
    
    // For each fallen sub-block in the grid. . .
    for (int i = 2; i < 22; i++)
    {
        for (int j = 2; j < 12; j++)
        {
            if (gridArray[i][j] != '.')
            {
                // Return a sprite of the appropriate colour.
                char colour = gridArray[i][j];
                playedBlockSprites.push_back(createSpriteForSubBlock(colour, j, i));
            }
        }
    }
    
    return playedBlockSprites;
}


vector <shared_ptr <Sprite>> Grid::getSpritesForActiveBlock()
{
    vector <shared_ptr <Sprite>> activeBlockSprites;
    
    vector <vector <char>> orientation = *(activeBlock->orientation);
    
    // For each sub-block of the active block. . .
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (orientation[i][j] != '.')
            {
                // Get grid position.
                int subBlockGridPosX = activeBlock->gridPosX + j;
                int subBlockGridPosY = activeBlock->gridPosY + i;
                
                // (Do not return sprite if subblock is above upper grid boundary).
                if (subBlockGridPosY > 1)
                {
                    // Return a sprite of the appropriate colour.
                    char colour = orientation[i][j];
                    activeBlockSprites.push_back(createSpriteForSubBlock(colour, subBlockGridPosX, subBlockGridPosY));
                }
            }
        }
    }
    
    return activeBlockSprites;
}


shared_ptr <Sprite> Grid::createSpriteForSubBlock(char colour, int gridPosX, int gridPosY)
{
    int w = 8;
    int h = 8;
    
    // Convert grid position of sub-block to global coordinates for sprite.
    int x = (w * (gridPosX - 7)) + (w / 2);
    int y = (h * (-gridPosY + 11)) + (h / 2);
    
    shared_ptr <WrappedGpuImage> image = getImageForSubBlock(colour);
    
    return make_shared <Sprite> (image, x, y, w, h);
}


shared_ptr <WrappedGpuImage> Grid::getImageForSubBlock(char colour)
{
    switch(colour)
    {
        case 'D':
            return imageBank->darkSubBlock;
            
        case 'B':
            return imageBank->blueSubBlock;
            
        case 'G':
            return imageBank->greenSubBlock;
            
        case 'O':
            return imageBank->orangeSubBlock;
            
        case 'P':
            return imageBank->pinkSubBlock;
            
        case 'I':
            return imageBank->indigoSubBlock;
            
        case 'R':
            return imageBank->redSubBlock;
            
        case 'Y':
            return imageBank->yellowSubBlock;
        
        default:
            return nullptr;
    }
}


void Grid::toggleGridCover()
{
    if (gridCover->getImage() == imageBank->transparent)
    {
        gridCover->setImage(imageBank->gridCoverPaused);
    }
    else
    {
        gridCover->setImage(imageBank->transparent);
    }
}


void Grid::setHighScore(int newHighScore)
{
    highScore = newHighScore;
}


int Grid::getLevel()
{
    return level;
}


int Grid::getScore()
{
    return score;
}


int Grid::getHighscore()
{
    return highScore;
}


int Grid::getLineCount()
{
    return lineCount;
}


array <int, 7> Grid::getBlockCounts()
{
    return blockCounts;
}


int Grid::getNextBlockIdentifier()
{
    return nextBlock->identifier;
}
