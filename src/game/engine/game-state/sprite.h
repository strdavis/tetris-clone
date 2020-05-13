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

#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_rect.h>

class WrappedGpuImage;
class GPU_Image;


// Represents an image with a corresponding position and size.
//
// Sprites do not contain image data, keeping them lightweight.
// They point to images in the image bank,
// and contain information about how to draw those images.
//
// Coordinates for sprites are relative to the position of
// the game element that owns them.
class Sprite
{
public:
    Sprite(std::shared_ptr <WrappedGpuImage> image, int x = 0, int y = 0, int w = 0, int h = 0);
    Sprite(std::shared_ptr <Sprite> sprite);
    Sprite();
    
    void setImage(std::shared_ptr <WrappedGpuImage> newImage);
    void setSize(Uint16 w, Uint16 h);
    void setPos(int x, int y);
    int getWidth();
    int getHeight();
    SDL_Point getPos();
    GPU_Image* getRawImage();
    std::shared_ptr <WrappedGpuImage> getImage();

private:
    int width;
    int height;
    SDL_Point pos;
    std::shared_ptr <WrappedGpuImage> image;
};
