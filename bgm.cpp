//
//  bgm.cpp
//  bgm
//
//  Created by 陳柏諭 on 2022/1/8.
//

#include "bgm.hpp"
Mix_Chunk* bgm=NULL;
bool music::init()
{
    bool success=true;
    //Initialize SDL_mixer
   if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
   {
       printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
       success = false;
   }
    return success;
}
bool music::load()
{
    bool success=true;
    bgm = Mix_LoadWAV( "Laconic Granny - Kevin MacLeod .wav" );
    if( bgm == NULL )
    {
        printf( "Failed to load sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }
    return success;
}
bool music::close()
{
    Mix_FreeChunk( bgm );
    bgm=NULL;
    Mix_Quit();
}
void music::play()
{
    //if the game isn't over but no music is playing, keep playing.
    while (!gover && Mix_PlayingMusic() == 0)
    {
        Mix_PlayChannel( -1, bgm, 0 );
    }
    if (gover && Mix_PlayingMusic()==1)
    {
        Mix_PauseMusic();
    }
    
    
}

