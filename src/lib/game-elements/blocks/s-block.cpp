#include "s-block.h"

#include <iostream>

using std::vector;


SBlock::SBlock(char (*gridArray)[23][14], int level)
    : Block(gridArray, level)
{
    identifier = 6;
    
    gridPosX = 4;
    gridPosY = 1;
    
    orientations.push_back(orientation0);
    orientations.push_back(orientation1);
    
    orientation = orientations.begin();
}
