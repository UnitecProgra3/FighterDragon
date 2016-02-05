#include "Character.h"

std::string toString(int number)
{
    if (number == 0)
        return "0";

    if(number < 0)
        return "-"+toString(-number);

    std::string temp="";
    std::string returnvalue="";
    while (number>0)
    {
        temp+=number%10+48;
        number/=10;
    }
    for (int i=0;i<(int)temp.length();i++)
        returnvalue+=temp[temp.length()-i-1];
    return returnvalue;
}

Character::Character(SDL_Renderer* renderer)
{
    moves["idle"]=getMove(renderer,"idle",4);
    moves["kick"]=getMove(renderer,"kick",6);
    moves["punch"]=getMove(renderer,"punch",3);
    moves["walk"]=getMove(renderer,"walk",5);

    this->current_move = "walk";
}

Move* Character::getMove(SDL_Renderer *renderer, string name, int sprite_amount)
{
    vector<Sprite*>sprites;
    for(int i=1;i<=sprite_amount;i++)
    {
        string path="assets/" + name + "/" + toString(i) + ".png";
        sprites.push_back(new Sprite(renderer,path,75));
    }
    return new Move(renderer,sprites);
}

Character::~Character()
{
    //dtor
}

void Character::draw()
{
    moves[current_move]->draw();
}
