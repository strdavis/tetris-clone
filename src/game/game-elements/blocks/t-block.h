#pragma once

#include <memory>
#include <vector>

#include "block.h"


class TBlock : public Block
{
public:
    TBlock(char (*gridArray)[23][14], int level);
    
private:
    std::vector <std::vector <char>> orientation0
    {
        {'.','.','.','.'},
        {'.','.','I','.'},
        {'.','I','I','I'},
        {'.','.','.','.'}
    };
    
    std::vector <std::vector <char>> orientation1
    {
        {'.','.','.','.'},
        {'.','.','I','.'},
        {'.','.','I','I'},
        {'.','.','I','.'}
    };
    
    std::vector <std::vector <char>> orientation2
    {
        {'.','.','.','.'},
        {'.','.','.','.'},
        {'.','I','I','I'},
        {'.','.','I','.'}
    };
    
    std::vector <std::vector <char>> orientation3
    {
        {'.','.','.','.'},
        {'.','.','I','.'},
        {'.','I','I','.'},
        {'.','.','I','.'}
    };
};
