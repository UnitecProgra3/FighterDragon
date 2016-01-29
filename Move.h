#ifndef MOVE_H
#define MOVE_H

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

#include <iostream>
#include <vector>
#include "Sprite.h"
using namespace std;

class Move
{
    public:
        vector<Sprite*> sprites;
        SDL_Renderer* renderer;
        Move(SDL_Renderer* renderer);
        int current_sprite;
        int frame;
        int current_sprite_frame;
        virtual ~Move();
        void draw();
    protected:
    private:
};

#endif // MOVE_H
