/*
* MIT License
*
* Copyright (c) 2020 Spencer Davis
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/


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
