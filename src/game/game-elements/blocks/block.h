#pragma once

#include <memory>
#include <vector>

#include "game-element.h"

struct InputData;


// The active block, manipulated by the player.
// Controls automatic descent speed.
//
// Subclasses contain 2D vectors or chars
// representing their possible orientations.
// These vectors are compared against grid contents
// to determine validity of moves.
class Block : GameElement
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
    void controlDescent(InputData inputData);
    int calculateDescentDelay(int level);
    bool checkValidPosition();
    
    char (*gridArray)[23][14];
    int identifier;
    int gridPosX;
    int gridPosY;
    int framesSinceLeftMove;
    int framesSinceRightMove;
    int framesSinceDownMove;
    int framesSinceDescent;
    int lateralMoveDelay;
    int fastDropDelay;
    int descentDelay;
    bool hasReachedBottom;
    std::vector <std::vector <std::vector <char>>> orientations;
    std::vector <std::vector <std::vector <char>>>::iterator orientation;
};
