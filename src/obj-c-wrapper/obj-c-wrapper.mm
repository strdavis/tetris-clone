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


#import "obj-c-wrapper.h"

#include <iostream>
#include <string>

#include "engine.h"

using namespace std;



@interface ObjCWrapper ()

@property Engine *tetris;

@end



@implementation ObjCWrapper

- (void) initEngine
{
    string appSupportDirectory = [self getAppSupportDirectory];
    
    _tetris = new Engine(appSupportDirectory);
    
    _tetris->runGameLoop();
    
    // Upon deletion of _engine
    exit(EXIT_SUCCESS);
}

- (string) getAppSupportDirectory
{
    NSFileManager *fileManager = [NSFileManager defaultManager];
    
    // Get application support directory URL in user domain.
    NSArray *URLs = [fileManager URLsForDirectory:NSApplicationSupportDirectory
                                        inDomains:NSUserDomainMask];
    
    if ([URLs count] == 0)
    {
        cout << "Could not find application support directories." << endl;
    }
    
    // Create URL for support directory for this game.
    NSURL *baseURL = [URLs objectAtIndex:0];
    NSString *directoryName = @"tetris";
    NSURL *supportDirectoryURL = [NSURL URLWithString:directoryName
                                 relativeToURL:baseURL];

    // Create new directory at that URL if it does not exist.
    NSError *error;
    BOOL folderCreated = [fileManager createDirectoryAtURL:supportDirectoryURL
                               withIntermediateDirectories:YES
                                                attributes:nil
                                                     error:&error];
    
    if (!folderCreated)
    {
        cout << "Application support directory already exists." << endl;
    }
    
    // Convert directory URL to const char
    NSString *supportDirectoryStr = supportDirectoryURL.path;
    string supportDirectoryPath = [supportDirectoryStr UTF8String];
    
    // Adding trailing backslash to path here saves having to add it
    // every time we access items in the support directory.
    supportDirectoryPath += "/";
    
    return supportDirectoryPath;
}

@end
