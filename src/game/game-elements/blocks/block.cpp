#include "block.h"

#include <iostream>

#include "data-transfer-types.h"

using std::vector;
using std::shared_ptr;
using std::make_shared;


Block::Block(char (*gridArray)[23][14], int level)
    : GameElement(),
      gridArray(gridArray),
      framesSinceLeftMove(0),
      framesSinceRightMove(0),
      framesSinceDownMove(0),
      framesSinceDescent(0),
      lateralMoveDelay(4),
      fastDropDelay(1),
      descentDelay(calculateDescentDelay(level)),
      hasReachedBottom(false)
{
    
}


void Block::update(InputData inputData)
{
    if (inputData.keyStates.left.pressed) { moveLeft(); }
    
    if (inputData.keyStates.right.pressed) { moveRight(); }
    
    if (inputData.keyStates.down.pressed) { moveDown(); }
    
    if (inputData.keyStates.left.held) { moveLeftContinuously(); }
    
    if (inputData.keyStates.right.held) { moveRightContinuously(); }
    
    if (inputData.keyStates.down.held) { fastDrop(); }
    
    if (inputData.keyStates.z.pressed) { rotateLeft(); }
    
    if (inputData.keyStates.x.pressed) { rotateRight(); }
    
    controlDescent(inputData);
}


void Block::moveLeft()
{
    gridPosX--;
    framesSinceLeftMove = 0;
    
    if (!checkValidPosition()) { gridPosX++; };
}


void Block::moveRight()
{
    gridPosX++;
    framesSinceRightMove = 0;
    
    if (!checkValidPosition()) { gridPosX--; };
}


void Block::moveDown()
{
    gridPosY++;
    framesSinceDownMove = 0;
    
    if (!checkValidPosition())
    {
        gridPosY--;
        hasReachedBottom = true;
    };
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


void Block::controlDescent(InputData inputData)
{
    if ((framesSinceDescent > descentDelay) &&
        inputData.keyStates.down.held != true)
    {
        moveDown();
        framesSinceDescent = 0;
    }
    else
    {
        framesSinceDescent++;
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
        
    delay = delay - delayDecrement;//level 8 delay = 3 (same as fast-drop speed)
    
    if (delay < 1) {delay = 1;}//level 9 delay = 2 (insane)
        
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
