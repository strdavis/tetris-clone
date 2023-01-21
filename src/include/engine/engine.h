#pragma once

#include <memory>
#include <string>

struct ImageBank;

class FileManager;
class InputCollector;
class GameState;
class DisplayModule;


// Top-level node of game engine.
// Initializes engine components.
// Controls game loop.
class Engine
{
public:
    Engine(std::string appSupportDirectory);
    
    void runGameLoop();
    
private:
    void limitFPS(int fps, int frameStartTime);
    
    std::string appSupportDirectory;
    std::unique_ptr <FileManager> fileManager;
    std::unique_ptr <InputCollector> inputCollector;
    std::shared_ptr <DisplayModule> displayModule;
    std::shared_ptr <ImageBank> imageBank;
    std::shared_ptr <GameState> gameState;
};
