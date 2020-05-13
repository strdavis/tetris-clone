#include "l-block.h"

#include <iostream>

using std::vector;


LBlock::LBlock(char (*gridArray)[23][14], int level)
    : Block(gridArray, level)
{
    identifier = 4;
    
    gridPosX = 4;
    gridPosY = 1;
    
    orientations.push_back(orientation0);
    orientations.push_back(orientation1);
    orientations.push_back(orientation2);
    orientations.push_back(orientation3);
    
    orientation = orientations.begin();
}
