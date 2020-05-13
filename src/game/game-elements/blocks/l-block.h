#pragma once

#include <memory>
#include <vector>

#include "block.h"


class LBlock : public Block
{
public:
    LBlock(char (*gridArray)[23][14], int level);
    
private:
    
    std::vector <std::vector <char>> orientation0
    {
        {'.','.','.','.'},
        {'.','.','.','P'},
        {'.','P','P','P'},
        {'.','.','.','.'}
    };
    
    std::vector <std::vector <char>> orientation1
    {
        {'.','.','.','.'},
        {'.','.','P','.'},
        {'.','.','P','.'},
        {'.','.','P','P'}
    };
    
    std::vector <std::vector <char>> orientation2
    {
        {'.','.','.','.'},
        {'.','.','.','.'},
        {'.','P','P','P'},
        {'.','P','.','.'}
    };
    
    std::vector <std::vector <char>> orientation3
    {
        {'.','.','.','.'},
        {'.','P','P','.'},
        {'.','.','P','.'},
        {'.','.','P','.'}
    };
};
