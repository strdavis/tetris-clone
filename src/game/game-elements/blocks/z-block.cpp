#include "z-block.h"

#include <iostream>

using std::vector;


ZBlock::ZBlock(char (*gridArray)[23][14], int level)
    : Block(gridArray, level)
{
    identifier = 5;
    
    gridPosX = 5;
    gridPosY = 1;
    
    orientations.push_back(orientation0);
    orientations.push_back(orientation1);
    
    orientation = orientations.begin();
}
