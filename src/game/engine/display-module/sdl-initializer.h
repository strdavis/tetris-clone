#pragma once

class GPU_Target;


class SdlInitializer
{
public:
    SdlInitializer();
    
    GPU_Target* createSdlGpuWindow(int windowWidthWindowed,
                                   int windowHeightWindowed,
                                   int windowVirtualWidthWindowed,
                                   int windowVirtualHeightWindowed);
    
private:

};

