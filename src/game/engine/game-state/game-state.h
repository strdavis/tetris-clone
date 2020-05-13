#pragma once

#include <memory>
#include <vector>

struct InputData;
struct WindowFlags;
struct SaveData;
struct ImageBank;

class GameElement;
class Sprite;
class Background;
class Title;
class Instructions;
class NextBlockDisplay;
class LevelDisplay;
class HighScoreDisplay;
class ScoreDisplay;
class LineCountDisplay;
class BlockCountDisplay;
class Grid;


// Contains all game elements.
// Mediates interactions between game elements and engine components,
//
// Controls which elements are active.
// Mediates interactions between active elements.
//
// Can be queried for a vector of all sprites of active elements.
// Contains high-level game state descriptors (is running, is paused, etc).
class GameState
{
public:
    GameState(std::shared_ptr <ImageBank> imageBank);
    
    void update(InputData flags);
    void setRunStatus(bool status);
    void setPauseStatus(bool status);
    void setLoadedSaveData(SaveData saveData);
    bool getRunStatus();
    bool getPauseStatus();
    std::vector <std::shared_ptr <Sprite>> getSprites();
    WindowFlags getWindowFlags();
    SaveData getSaveData();
    
private:
    void checkForQuit(InputData inputData);
    void checkForReset(InputData inputData);
    void checkForPause(InputData inputData);
    void checkForFullscreenToggle(InputData inputData);
    
    bool runStatus;
    bool pauseStatus;
    bool fullscreen;
    
    std::shared_ptr <ImageBank> imageBank;
    std::shared_ptr <Background> background;
    std::shared_ptr <Title> title;
    std::shared_ptr <Instructions> instructions;
    std::shared_ptr <NextBlockDisplay> nextBlockDisplay;
    std::shared_ptr <LevelDisplay> levelDisplay;
    std::shared_ptr <HighScoreDisplay> highScoreDisplay;
    std::shared_ptr <ScoreDisplay> scoreDisplay;
    std::shared_ptr <LineCountDisplay> lineCountDisplay;
    std::shared_ptr <BlockCountDisplay> blockCountDisplay;
    std::shared_ptr <Grid> grid;
    std::vector <std::shared_ptr <GameElement>> activeElements;
};

