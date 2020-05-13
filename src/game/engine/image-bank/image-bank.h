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


#pragma once

#include <memory>

class WrappedGpuImage;


struct ImageBank
{
    ImageBank();
    
    // Sub-blocks
    std::shared_ptr <WrappedGpuImage> darkSubBlock;
    std::shared_ptr <WrappedGpuImage> blueSubBlock;
    std::shared_ptr <WrappedGpuImage> greenSubBlock;
    std::shared_ptr <WrappedGpuImage> indigoSubBlock;
    std::shared_ptr <WrappedGpuImage> orangeSubBlock;
    std::shared_ptr <WrappedGpuImage> pinkSubBlock;
    std::shared_ptr <WrappedGpuImage> redSubBlock;
    std::shared_ptr <WrappedGpuImage> yellowSubBlock;
    
    // Blocks
    std::shared_ptr <WrappedGpuImage> iBlock;
    std::shared_ptr <WrappedGpuImage> oBlock;
    std::shared_ptr <WrappedGpuImage> tBlock;
    std::shared_ptr <WrappedGpuImage> jBlock;
    std::shared_ptr <WrappedGpuImage> lBlock;
    std::shared_ptr <WrappedGpuImage> zBlock;
    std::shared_ptr <WrappedGpuImage> sBlock;
    
    // Colours
    std::shared_ptr <WrappedGpuImage> darkGrey;
    std::shared_ptr <WrappedGpuImage> white;
    std::shared_ptr <WrappedGpuImage> transparent;
    
    // Panel frames
    std::shared_ptr <WrappedGpuImage> gridFrame;
    std::shared_ptr <WrappedGpuImage> nextBlockFrame;
    std::shared_ptr <WrappedGpuImage> levelFrame;
    std::shared_ptr <WrappedGpuImage> highScoreFrame;
    std::shared_ptr <WrappedGpuImage> scoreFrame;
    std::shared_ptr <WrappedGpuImage> lineCountFrame;
    std::shared_ptr <WrappedGpuImage> statsFrame;
    
    // Level digits
    std::shared_ptr <WrappedGpuImage> level1;
    std::shared_ptr <WrappedGpuImage> level2;
    std::shared_ptr <WrappedGpuImage> level3;
    std::shared_ptr <WrappedGpuImage> level4;
    std::shared_ptr <WrappedGpuImage> level5;
    std::shared_ptr <WrappedGpuImage> level6;
    std::shared_ptr <WrappedGpuImage> level7;
    std::shared_ptr <WrappedGpuImage> level8;
    std::shared_ptr <WrappedGpuImage> level9;
    
    // Digits
    std::shared_ptr <WrappedGpuImage> digit0;
    std::shared_ptr <WrappedGpuImage> digit1;
    std::shared_ptr <WrappedGpuImage> digit2;
    std::shared_ptr <WrappedGpuImage> digit3;
    std::shared_ptr <WrappedGpuImage> digit4;
    std::shared_ptr <WrappedGpuImage> digit5;
    std::shared_ptr <WrappedGpuImage> digit6;
    std::shared_ptr <WrappedGpuImage> digit7;
    std::shared_ptr <WrappedGpuImage> digit8;
    std::shared_ptr <WrappedGpuImage> digit9;
   
    
    // Misc
    std::shared_ptr <WrappedGpuImage> title;
    std::shared_ptr <WrappedGpuImage> instructions;
    std::shared_ptr <WrappedGpuImage> gridCoverPaused;
};
