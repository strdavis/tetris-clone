//Enables use of NSObject
#import <Foundation/Foundation.h>



// Serves as intermediary between C++ and Cocoa functions.
// Initializes tetris main.
// Header is pure Obj-C.
// Source is Obj-C++.
@interface ObjCWrapper : NSObject

- (void) initEngine;

@end
