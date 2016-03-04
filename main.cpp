#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>
#include<list>
#include "Character.h"
#include "Button.h"
#include "DeviceButton.h"
#include "InputManager.h"

using namespace std;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *background;
SDL_Rect rect_background,rect_character;


int main( int argc, char* args[] )
{
    //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("Image Loading", 100, 100, 1200/*WIDTH*/, 600/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
    {
        return 20;
    }
    //SDL Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 30;
    }

    //Init textures
    background = IMG_LoadTexture(renderer,"fondo.png");
    rect_background.x = 0;
    rect_background.y = 0;
    rect_background.w = 500;
    rect_background.h = 250;

    Character* character = new Character(renderer,200,550,false,"assets/inputs_player1.txt");
    Character* character2 = new Character(renderer,600,550,true,"assets/inputs_player2.txt");

    map<DeviceButton*,Button*>input_map;

    int frame=0;

    double last_fame_ticks=SDL_GetTicks();

    //Main Loop
    while(true)
    {
        frame++;
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return 0;
            }
            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_d)
                    rect_character.x++;
                if(Event.key.keysym.sym == SDLK_a)
                    rect_character.x--;
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);


        SDL_RenderCopy(renderer, background, NULL, &rect_background);

        character->logic();
        character->draw();

        character2->logic();
        character2->draw();

        vector<Hitbox*>char1_hitboxes=character->getHitboxes();
        vector<Hitbox*>char2_hitboxes=character2->getHitboxes();

        for(int i=0;i<char1_hitboxes.size();i++)
        {
            for(int j=0;j<char2_hitboxes.size();j++)
            {
                SDL_Rect rect1 = char1_hitboxes[i]->rect;
                SDL_Rect rect2 = char2_hitboxes[j]->rect;

                if(!character->flipped)
                {
                    rect1.x+=character->x;
                }else
                {
                    rect1.x=-rect1.x-rect1.w+character->x;
                }
                rect1.y=-rect1.y+character->y;

                if(!character2->flipped)
                {
                    rect2.x+=character2->x;
                }else
                {
                    rect2.x=-rect2.x-rect2.w+character2->x;
                }
                rect2.y=-rect2.y+character2->y;
                if(collides(rect1,rect2))
                {
                    cout<<"Colision!"<<endl;
                }else
                {
                    //cout<<"No Colision!"<<endl;
                }
            }
        }

        if(character->x>character2->x)
        {
            character->flipped=true;
            character2->flipped=false;
        }else
        {
            character->flipped=false;
            character2->flipped=true;
        }

        double last_frame_length=SDL_GetTicks()-last_fame_ticks;
        double sleep_time=17-last_frame_length;
        //cout<<"Length: "<<last_frame_length<<", Sleep time: "<<sleep_time<<endl;
        if(sleep_time>0)
            SDL_Delay(sleep_time);
        last_fame_ticks=SDL_GetTicks();



//        drawRect(renderer,10,30,50,100,
//                 0,255,255,0);

        SDL_RenderPresent(renderer);
    }

	return 0;
}
