#include "Move.h"

Move::Move(SDL_Renderer* renderer)
{
    this->renderer=renderer;
    Sprite *sprite1=new Sprite(renderer,"assets/idle/1.png",75);
    Sprite *sprite2=new Sprite(renderer,"assets/idle/2.png",75);
    Sprite *sprite3=new Sprite(renderer,"assets/idle/3.png",75);
    Sprite *sprite4=new Sprite(renderer,"assets/idle/4.png",75);
    sprites.push_back(sprite1);
    sprites.push_back(sprite2);
    sprites.push_back(sprite3);
    sprites.push_back(sprite4);
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
