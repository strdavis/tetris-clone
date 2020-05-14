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


#include "image-bank.h"

#include "wrapped-gpu-image.h"

using std::make_shared;


ImageBank::ImageBank()
    : // Sub-blocks
      darkSubBlock      (make_shared <WrappedGpuImage> ("images/sub-blocks/black-sub-block.png")),
      blueSubBlock      (make_shared <WrappedGpuImage> ("images/sub-blocks/blue-sub-block.png")),
      greenSubBlock     (make_shared <WrappedGpuImage> ("images/sub-blocks/green-sub-block.png")),
      indigoSubBlock    (make_shared <WrappedGpuImage> ("images/sub-blocks/indigo-sub-block.png")),
      orangeSubBlock    (make_shared <WrappedGpuImage> ("images/sub-blocks/orange-sub-block.png")),
      pinkSubBlock      (make_shared <WrappedGpuImage> ("images/sub-blocks/pink-sub-block.png")),
      redSubBlock       (make_shared <WrappedGpuImage> ("images/sub-blocks/red-sub-block.png")),
      yellowSubBlock    (make_shared <WrappedGpuImage> ("images/sub-blocks/yellow-sub-block.png")),

      // Blocks
      iBlock            (make_shared <WrappedGpuImage> ("images/blocks/i-block.png")),
      oBlock            (make_shared <WrappedGpuImage> ("images/blocks/o-block.png")),
      tBlock            (make_shared <WrappedGpuImage> ("images/blocks/t-block.png")),
      jBlock            (make_shared <WrappedGpuImage> ("images/blocks/j-block.png")),
      lBlock            (make_shared <WrappedGpuImage> ("images/blocks/l-block.png")),
      zBlock            (make_shared <WrappedGpuImage> ("images/blocks/z-block.png")),
      sBlock            (make_shared <WrappedGpuImage> ("images/blocks/s-block.png")),

      // Colours
      darkGrey          (make_shared <WrappedGpuImage> ("images/colours/dark-grey.png")),
      white             (make_shared <WrappedGpuImage> ("images/colours/white.jpg")),
      transparent       (make_shared <WrappedGpuImage> ("images/colours/transparent.png")),

      // Frames
      gridFrame         (make_shared <WrappedGpuImage> ("images/frames/grid-frame.png")),
      nextBlockFrame    (make_shared <WrappedGpuImage> ("images/frames/next-block-frame.png")),
      levelFrame        (make_shared <WrappedGpuImage> ("images/frames/level-frame.png")),
      highScoreFrame    (make_shared <WrappedGpuImage> ("images/frames/high-score-frame.png")),
      scoreFrame        (make_shared <WrappedGpuImage> ("images/frames/score-frame.png")),
      lineCountFrame    (make_shared <WrappedGpuImage> ("images/frames/line-count-frame.png")),
      statsFrame        (make_shared <WrappedGpuImage> ("images/frames/stats-frame.png")),

      // Level digits
      level1            (make_shared <WrappedGpuImage> ("images/level-digits/level-1.png")),
      level2            (make_shared <WrappedGpuImage> ("images/level-digits/level-2.png")),
      level3            (make_shared <WrappedGpuImage> ("images/level-digits/level-3.png")),
      level4            (make_shared <WrappedGpuImage> ("images/level-digits/level-4.png")),
      level5            (make_shared <WrappedGpuImage> ("images/level-digits/level-5.png")),
      level6            (make_shared <WrappedGpuImage> ("images/level-digits/level-6.png")),
      level7            (make_shared <WrappedGpuImage> ("images/level-digits/level-7.png")),
      level8            (make_shared <WrappedGpuImage> ("images/level-digits/level-8.png")),
      level9            (make_shared <WrappedGpuImage> ("images/level-digits/level-9.png")),

      // Digits
      digit0            (make_shared <WrappedGpuImage> ("images/digits/digit-0.png")),
      digit1            (make_shared <WrappedGpuImage> ("images/digits/digit-1.png")),
      digit2            (make_shared <WrappedGpuImage> ("images/digits/digit-2.png")),
      digit3            (make_shared <WrappedGpuImage> ("images/digits/digit-3.png")),
      digit4            (make_shared <WrappedGpuImage> ("images/digits/digit-4.png")),
      digit5            (make_shared <WrappedGpuImage> ("images/digits/digit-5.png")),
      digit6            (make_shared <WrappedGpuImage> ("images/digits/digit-6.png")),
      digit7            (make_shared <WrappedGpuImage> ("images/digits/digit-7.png")),
      digit8            (make_shared <WrappedGpuImage> ("images/digits/digit-8.png")),
      digit9            (make_shared <WrappedGpuImage> ("images/digits/digit-9.png")),

      // Misc
      title             (make_shared <WrappedGpuImage> ("images/misc/title-red.png")),
      instructions      (make_shared <WrappedGpuImage> ("images/misc/instructions.png")),
      gridCoverPaused   (make_shared <WrappedGpuImage> ("images/misc/grid-cover-paused.png"))
{
    
}
