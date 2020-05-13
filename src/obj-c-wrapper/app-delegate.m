#import "app-delegate.h"



@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
    _wrapper = [[ObjCWrapper alloc] init];
    [_wrapper initEngine];
}

- (void)applicationWillTerminate:(NSNotification *)aNotification
{
    
}

@end
