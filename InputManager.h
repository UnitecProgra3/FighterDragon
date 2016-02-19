#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include<SDL2/SDL.h>
#include "Move.h"
#include "Button.h"
#include "DeviceButton.h"

#include <map>
#include <list>
using namespace std;

class InputManager
{
    public:
        map<char,DeviceButton*>input_map;
        list<Button*>buffer;
        vector<char>possible_buttons;
        InputManager();
        bool isPressed(Button button);
        bool isInBuffer(Move move);
        void update();
        virtual ~InputManager();
    protected:
    private:
};

#endif // INPUTMANAGER_H
