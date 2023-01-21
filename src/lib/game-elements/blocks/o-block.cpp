#include "o-block.h"

#include <iostream>

using std::vector;


OBlock::OBlock(char (*gridArray)[23][14], int level)
    : Block(gridArray, level)
{
    identifier = 1;
    
    gridPosX = 5;
    gridPosY = 1;
    
    orientations.push_back(orientation0);
    
    orientation = orientations.begin();
}
