#pragma once

#include <memory>
#include <vector>

#include "block.h"


class JBlock : public Block
{
public:
    JBlock(char (*gridArray)[23][14], int level);
    
private:
    
    std::vector <std::vector <char>> orientation0
    {
        {'.','.','.','.'},
        {'.','O','.','.'},
        {'.','O','O','O'},
        {'.','.','.','.'}
    };
    
    std::vector <std::vector <char>> orientation1
    {
        {'.','.','.','.'},
        {'.','.','O','O'},
        {'.','.','O','.'},
        {'.','.','O','.'}
    };
    
    std::vector <std::vector <char>> orientation2
    {
        {'.','.','.','.'},
        {'.','.','.','.'},
        {'.','O','O','O'},
        {'.','.','.','O'}
    };
    
    std::vector <std::vector <char>> orientation3
    {
        {'.','.','.','.'},
        {'.','.','O','.'},
        {'.','.','O','.'},
        {'.','O','O','.'}
    };
};
