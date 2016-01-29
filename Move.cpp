#include "Move.h"

Move::Move(SDL_Renderer* renderer,vector<Sprite*>sprites)
{
    this->renderer=renderer;
    for(int i=0;i<sprites.size();i++)
    {
        this->sprites.push_back(sprites[i]);
    }
    current_sprite=0;
    frame=0;
    current_sprite_frame=0;
}

Move::~Move()
{
    //dtor
}

void Move::draw()
{
    Sprite* sprite = sprites[current_sprite];
    sprite->draw();
    current_sprite_frame++;
    if(current_sprite_frame>=sprite->frames)
    {
        current_sprite++;
        if(current_sprite>=sprites.size())
            current_sprite=0;
        current_sprite_frame=0;
    }

    frame++;
}
