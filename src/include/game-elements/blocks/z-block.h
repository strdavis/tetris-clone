#pragma once

#include <memory>
#include <vector>

#include "block.h"


class ZBlock : public Block
{
public:
    ZBlock(char (*gridArray)[23][14], int level);
    
private:
    std::vector <std::vector <char>> orientation0
    {
        {'.','.','.','.'},
        {'Y','Y','.','.'},
        {'.','Y','Y','.'},
        {'.','.','.','.'}
    };
    
    std::vector <std::vector <char>> orientation1
    {
        {'.','.','Y','.'},
        {'.','Y','Y','.'},
        {'.','Y','.','.'},
        {'.','.','.','.'}
    };
};
