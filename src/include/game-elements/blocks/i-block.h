#pragma once

#include <memory>
#include <vector>

#include "block.h"


class IBlock : public Block
{
public:
    IBlock(char (*gridArray)[23][14], int level);
    
private:
    std::vector <std::vector <char>> orientation0
    {
        {'.','.','.','.'},
        {'.','.','.','.'},
        {'B','B','B','B'},
        {'.','.','.','.'}
    };
    
    std::vector <std::vector <char>> orientation1
    {
        {'.','.','B','.'},
        {'.','.','B','.'},
        {'.','.','B','.'},
        {'.','.','B','.'}
    };
};
