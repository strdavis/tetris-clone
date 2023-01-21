#include "image-bank.h"

#include "wrapped-gpu-image.h"

using std::make_shared;


ImageBank::ImageBank(std::string appSupportDirectory)
    : // Sub-blocks
      darkSubBlock      (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/sub-blocks/black-sub-block.png")).c_str())),
      blueSubBlock      (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/sub-blocks/blue-sub-block.png")).c_str())),
      greenSubBlock     (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/sub-blocks/green-sub-block.png")).c_str())),
      indigoSubBlock    (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/sub-blocks/indigo-sub-block.png")).c_str())),
      orangeSubBlock    (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/sub-blocks/orange-sub-block.png")).c_str())),
      pinkSubBlock      (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/sub-blocks/pink-sub-block.png")).c_str())),
      redSubBlock       (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/sub-blocks/red-sub-block.png")).c_str())),
      yellowSubBlock    (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/sub-blocks/yellow-sub-block.png")).c_str())),

      // Blocks
      iBlock            (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/blocks/i-block.png")).c_str())),
      oBlock            (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/blocks/o-block.png")).c_str())),
      tBlock            (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/blocks/t-block.png")).c_str())),
      jBlock            (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/blocks/j-block.png")).c_str())),
      lBlock            (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/blocks/l-block.png")).c_str())),
      zBlock            (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/blocks/z-block.png")).c_str())),
      sBlock            (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/blocks/s-block.png")).c_str())),

      // Colours
      darkGrey          (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/colours/dark-grey.png")).c_str())),
      white             (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/colours/white.jpg")).c_str())),
      transparent       (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/colours/transparent.png")).c_str())),

      // Frames
      gridFrame         (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/frames/grid-frame.png")).c_str())),
      nextBlockFrame    (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/frames/next-block-frame.png")).c_str())),
      levelFrame        (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/frames/level-frame.png")).c_str())),
      highScoreFrame    (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/frames/high-score-frame.png")).c_str())),
      scoreFrame        (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/frames/score-frame.png")).c_str())),
      lineCountFrame    (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/frames/line-count-frame.png")).c_str())),
      statsFrame        (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/frames/stats-frame.png")).c_str())),

      // Level digits
      level1            (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/level-digits/level-1.png")).c_str())),
      level2            (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/level-digits/level-2.png")).c_str())),
      level3            (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/level-digits/level-3.png")).c_str())),
      level4            (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/level-digits/level-4.png")).c_str())),
      level5            (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/level-digits/level-5.png")).c_str())),
      level6            (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/level-digits/level-6.png")).c_str())),
      level7            (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/level-digits/level-7.png")).c_str())),
      level8            (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/level-digits/level-8.png")).c_str())),
      level9            (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/level-digits/level-9.png")).c_str())),

      // Digits
      digit0            (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/digits/digit-0.png")).c_str())),
      digit1            (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/digits/digit-1.png")).c_str())),
      digit2            (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/digits/digit-2.png")).c_str())),
      digit3            (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/digits/digit-3.png")).c_str())),
      digit4            (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/digits/digit-4.png")).c_str())),
      digit5            (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/digits/digit-5.png")).c_str())),
      digit6            (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/digits/digit-6.png")).c_str())),
      digit7            (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/digits/digit-7.png")).c_str())),
      digit8            (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/digits/digit-8.png")).c_str())),
      digit9            (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/digits/digit-9.png")).c_str())),

      // Misc
      title             (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/misc/title-red.png")).c_str())),
      instructions      (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/misc/instructions.png")).c_str())),
      gridCoverPaused   (make_shared <WrappedGpuImage> ((appSupportDirectory + std::string("/img/misc/grid-cover-paused.png")).c_str()))
{
    
}
