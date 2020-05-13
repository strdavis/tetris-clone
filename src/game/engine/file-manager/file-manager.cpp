#include "file-manager.h"

#include "data-transfer-types.h"

using std::ifstream;
using std::ofstream;
using std::endl;
using std::string;


FileManager::FileManager(string appSupportDirectory)
    : appSupportDirectory(appSupportDirectory)
{
    
}


SaveData FileManager::loadSaveData()
{
    SaveData saveData;
    ifstream saveDataIn;
    
    string pathToSaveFile = appSupportDirectory + "save-data.txt";
    
    // Open save file in read mode.
    // If save file does not exist, create one.
    // Mode "app" -- output operations are appended to end of file,
    // ie, open file without overwriting.
    saveDataIn.open(pathToSaveFile, ifstream::app);
    
    // Move pointer to start of file.
    saveDataIn.seekg(0);
        
    //If file is not empty. . .
    if (saveDataIn.peek() != ifstream::traits_type::eof())
    {
        //Read value from first line in file (high score).
        saveDataIn >> saveData.highScore;
        saveDataIn.close();
    }
    else
    {
        saveDataIn.close();
    }
        
    return saveData;
}


void FileManager::storeSaveData(SaveData saveData)
{
    string pathToSaveFile = appSupportDirectory + "save-data.txt";
    
    ofstream saveDataOut;
    
    // Open save file in write mode.
    // Mode "trunc" -- clear data in file when it is opened.
    saveDataOut.open(pathToSaveFile, ofstream::trunc);
    
    // Move pointer to start of file
    saveDataOut.seekp(0);
    
    //Write to file
    saveDataOut << saveData.highScore << endl;
    saveDataOut.flush();
    saveDataOut.close();
}
