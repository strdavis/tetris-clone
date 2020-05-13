#include "i-block.h"

#include <iostream>

using std::vector;


IBlock::IBlock(char (*gridArray)[23][14], int level)
    : Block(gridArray, level)
{
    identifier = 0;
    
    gridPosX = 5;
    gridPosY = 0;
    
    orientations.push_back(orientation0);
    orientations.push_back(orientation1);
    
    orientation = orientations.begin();
}
