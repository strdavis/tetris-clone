#pragma once

#include <memory>
#include <vector>

#include "block.h"


class SBlock : public Block
{
public:
    SBlock(char (*gridArray)[23][14], int level);
    
private:
    std::vector <std::vector <char>> orientation0
    {
        {'.','.','.','.'},
        {'.','.','G','G'},
        {'.','G','G','.'},
        {'.','.','.','.'}
    };
    
    std::vector <std::vector <char>> orientation1
    {
        {'.','G','.','.'},
        {'.','G','G','.'},
        {'.','.','G','.'},
        {'.','.','.','.'}
    };
};
