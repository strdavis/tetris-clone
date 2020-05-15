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


#include "block.h"

#include <iostream>

#include "data-transfer-types.h"

using std::vector;
using std::shared_ptr;
using std::make_shared;

using std::cout;
using std::endl;


Block::Block(char (*gridArray)[23][14], int level)
    : GameElement(),
      gridArray(gridArray),
      framesSinceLeftMove(0),
      framesSinceRightMove(0),
      framesSinceDownMove(0),
      framesSinceAutoDescent(0),
      lateralMoveDelay(4),
      fastDropDelay(1),
      descentDelay(calculateDescentDelay(level)),
      hasReachedBottom(false),
      fastDropFlag(false)
{
    
}


void Block::update(InputData inputData)
{
    resetFlags();
    
    if (inputData.keyStates.z.pressed) { rotateLeft(); }
    
    if (inputData.keyStates.x.pressed) { rotateRight(); }
    
    if (inputData.keyStates.left.pressed) { moveLeft(); }
    
    if (inputData.keyStates.right.pressed) { moveRight(); }
    
    if (inputData.keyStates.left.held) { moveLeftContinuously(); }
    
    if (inputData.keyStates.right.held) { moveRightContinuously(); }
    
    if (inputData.keyStates.down.pressed) { moveDown(); }
    
    if (inputData.keyStates.down.held) { fastDrop(); }
    
    controlAutoDescent(inputData);
}


void Block::moveLeft()
{
    gridPosX--;
    framesSinceLeftMove = 0;
    
    if (!checkValidPosition()) { gridPosX++; }
}


void Block::moveRight()
{
    gridPosX++;
    framesSinceRightMove = 0;
    
    if (!checkValidPosition()) { gridPosX--; }
}


void Block::moveDown()
{
    gridPosY++;
    framesSinceDownMove = 0;
    
    if (!checkValidPosition())
    {
        gridPosY--;
        hasReachedBottom = true;
    }
    else if (framesSinceAutoDescent != 0) // If not auto-descent
    {
        fastDropFlag = true;
    }
}


void Block::moveLeftContinuously()
{
    if (framesSinceLeftMove > lateralMoveDelay)
    {
        moveLeft();
    }
    else
    {
        framesSinceLeftMove++;
    }
}


void Block::moveRightContinuously()
{
    if (framesSinceRightMove > lateralMoveDelay)
    {
        moveRight();
    }
    else
    {
        framesSinceRightMove++;
    }
}


void Block::fastDrop()
{
    if (framesSinceDownMove > fastDropDelay)
    {
        moveDown();
        fastDropFlag = true;
    }
    else
    {
        framesSinceDownMove++;
    }
}


void Block::rotateLeft()
{
    if (orientation == orientations.begin())
    {
        orientation = orientations.end() - 1;
    }
    else
    {
        orientation--;
    }
    
    if (!checkValidPosition()) { rotateRight(); };
}


void Block::rotateRight()
{
    if (orientation == orientations.end() - 1)
    {
        orientation = orientations.begin();
    }
    else
    {
        orientation++;
    }
    
    if (!checkValidPosition()) { rotateLeft(); };
}


void Block::controlAutoDescent(InputData inputData)
{
    if ((framesSinceAutoDescent > descentDelay) &&
        inputData.keyStates.down.held != true)
    {
        framesSinceAutoDescent = 0;
        moveDown();
    }
    else
    {
        framesSinceAutoDescent++;
    }
}


int Block::calculateDescentDelay(int level)
{
    // Decrements in delay get smaller as level increases.
    // This results in the best UX, since small differences in delay
    // are more noticeable at higher levels.
    // ie a drop from 52 to 51 frames is trivial,
    // while a drop from 2 frames to 1 doubles the speed.
    int delay = 52;
    int delayDecrement = 0;
    int delayDecrementBase = 20;
    for (int i = 1; i < level; i++)
    {
        delayDecrement = delayDecrement + (delayDecrementBase / i);
    }
        
    delay = delay - delayDecrement;
    
    if (delay < 1) {delay = 1;} // Level 9 delay = 1 (same as fast-drop delay).
        
    return delay;
}


bool Block::checkValidPosition()
{
    // Rows
    for (int i = 0; i < 4; i++)
    {
        // Columns
        for (int j = 0; j < 4; j++)
        {
            if ((*orientation)[i][j] != '.')
            {
                if ((*gridArray)[i + gridPosY][j + gridPosX] != '.')
                {
                    return false;
                }
            }
        }
    }
    
    return true;
}


void Block::resetFlags()
{
    if (fastDropFlag) { fastDropFlag = false; }
}
