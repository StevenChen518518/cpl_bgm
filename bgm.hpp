//
//  bgm.hpp
//  bgm
//
//  Created by 陳柏諭 on 2022/1/8.
//

#ifndef bgm_hpp
#define bgm_hpp
#endif /* bgm_hpp */
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <stdio.h>
#include <string>
class music
{
public:
    bool init();
    bool load();
    bool close();
    void play();
    bool gover;
};
