#pragma once

#include <fstream>
#include <string>

struct SaveData;


// Saves and loads file data.
class FileManager
{
public:
    FileManager(std::string appSupportDirectory);
    
    void storeSaveData(SaveData saveData);
    SaveData loadSaveData();
    
private:
    std::string appSupportDirectory;
    
};
