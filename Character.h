#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <map>
#include "Move.h"
using namespace std;

class Character
{
    public:
        map<string,Move*>moves;
        Character();
        virtual ~Character();
    protected:
    private:
};

#endif // CHARACTER_H
