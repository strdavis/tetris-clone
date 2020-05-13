#pragma once

#include <memory>
#include <array>

#include "panel.h"

#include "data-transfer-types.h"

struct ImageBank;

class Sprite;
class WrappedGpuImage;
class Block;
class RandomNumberGenerator;


// Contains all core data and logic for the tetris game,
// not including those for manipulating the active block,
//
// Contains a 2D array of chars representing the grid.
// Block colours are represented on the grid as follows:
//     -> 'B' = blue
//     -> 'R' = red
//     -> 'I' = indigo
//     -> 'O' = orange
//     -> 'P' = pink
//     -> 'Y' = yellow
//     -> 'G' = green
//
// When queried for a list of sprites,
// it scans the grid and returns sprites corresponding
// to these block colours.
class Grid : public Panel
{
public:
    Grid(std::shared_ptr <ImageBank> imageBank);
    
    void update(InputData inputData) override;
    std::vector <std::shared_ptr <Sprite>> getSprites() override;
    
    void reset();
    void toggleGridCover();
    void setHighScore(int newHighScore);
    int getLevel();
    int getScore();
    int getHighscore();
    int getLineCount();
    int getNextBlockIdentifier();
    std::array <int, 7> getBlockCounts();
    
private:
    void activateNextBlock();
    void copyActiveBlockToGrid();
    void updateScore(int linesCleared);
    void checkForLevelUp();
    void checkForGameOver();
    void collapseFromRow(int row);
    int clearLines();
    std::shared_ptr <Block> generateRandomBlock();
    std::shared_ptr <WrappedGpuImage> getImageForSubBlock(char colour);
    std::vector <std::shared_ptr <Sprite>> getPlayedBlockSprites();
    std::vector <std::shared_ptr <Sprite>> getActiveBlockSprites();
    
    int level;
    int score;
    int highScore;
    int lineCount;
    bool gameOver;
    std::array <int, 7> blockCounts;
    std::shared_ptr <Block> activeBlock;
    std::shared_ptr <Block> nextBlock;
    std::shared_ptr <Sprite> gridCover;
    std::shared_ptr <RandomNumberGenerator> rng;
    
    char gridArray[23][14] =
    {
        {'.','#','.','.','.','.','.','.','.','.','.','.','#','.'},
        {'.','#','.','.','.','.','.','.','.','.','.','.','#','.'},
        {'.','#','.','.','.','.','.','.','.','.','.','.','#','.'},
        {'.','#','.','.','.','.','.','.','.','.','.','.','#','.'},
        {'.','#','.','.','.','.','.','.','.','.','.','.','#','.'},
        {'.','#','.','.','.','.','.','.','.','.','.','.','#','.'},
        {'.','#','.','.','.','.','.','.','.','.','.','.','#','.'},
        {'.','#','.','.','.','.','.','.','.','.','.','.','#','.'},
        {'.','#','.','.','.','.','.','.','.','.','.','.','#','.'},
        {'.','#','.','.','.','.','.','.','.','.','.','.','#','.'},
        {'.','#','.','.','.','.','.','.','.','.','.','.','#','.'},
        {'.','#','.','.','.','.','.','.','.','.','.','.','#','.'},
        {'.','#','.','.','.','.','.','.','.','.','.','.','#','.'},
        {'.','#','.','.','.','.','.','.','.','.','.','.','#','.'},
        {'.','#','.','.','.','.','.','.','.','.','.','.','#','.'},
        {'.','#','.','.','.','.','.','.','.','.','.','.','#','.'},
        {'.','#','.','.','.','.','.','.','.','.','.','.','#','.'},
        {'.','#','.','.','.','.','.','.','.','.','.','.','#','.'},
        {'.','#','.','.','.','.','.','.','.','.','.','.','#','.'},
        {'.','#','.','.','.','.','.','.','.','.','.','.','#','.'},
        {'.','#','.','.','.','.','.','.','.','.','.','.','#','.'},
        {'.','#','.','.','.','.','.','.','.','.','.','.','#','.'},
        {'.','#','#','#','#','#','#','#','#','#','#','#','#','.'}
    };
};
