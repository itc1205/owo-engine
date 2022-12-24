#pragma once

#include "texture.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_video.h>

#include <functional>
#include <vector>



class entity
{
    private:
        int cordX = 0;
        int cordY = 0;

        mTexture *mTexture;
    
    public:
        int GetCordX()
        {
            return cordX;
        }
        int GetCordY()
        {
            return cordY;
        }
        void draw()
        {

        }
        void move()
        {
            
        }


};
