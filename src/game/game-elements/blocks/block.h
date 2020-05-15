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
#include <vector>

#include "game-element.h"

struct InputData;


// The active block, manipulated by the player.
// Controls automatic descent speed.
//
// Subclasses contain 2D vectors of chars
// representing the possible orientations of the block type.
// These vectors are compared against grid contents
// to determine validity of moves.
class Block : public GameElement
{
public:
    Block(char (*gridArray)[23][14], int level);
    
    void update(InputData inputData) override;
    
    void moveLeft();
    void moveRight();
    void moveDown();
    void moveLeftContinuously();
    void moveRightContinuously();
    void fastDrop();
    void rotateLeft();
    void rotateRight();
    void controlAutoDescent(InputData inputData);
    void resetFlags();
    int calculateDescentDelay(int level);
    bool checkValidPosition();
    
    char (*gridArray)[23][14];
    int identifier;
    int gridPosX;
    int gridPosY;
    int framesSinceLeftMove;
    int framesSinceRightMove;
    int framesSinceDownMove;
    int framesSinceAutoDescent;
    int lateralMoveDelay;
    int fastDropDelay;
    int descentDelay;
    bool hasReachedBottom;
    bool fastDropFlag;
    std::vector <std::vector <std::vector <char>>> orientations;
    std::vector <std::vector <std::vector <char>>>::iterator orientation;
};
