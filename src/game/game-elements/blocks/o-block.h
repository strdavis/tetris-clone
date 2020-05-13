#pragma once

#include <memory>
#include <vector>

#include "block.h"


class OBlock : public Block
{
public:
    OBlock(char (*gridArray)[23][14], int level);
    
private:
    std::vector <std::vector <char>> orientation0
    {
        {'.','.','.','.'},
        {'.','R','R','.'},
        {'.','R','R','.'},
        {'.','.','.','.'}
    };
};
