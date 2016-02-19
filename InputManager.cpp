#include "InputManager.h"

InputManager::InputManager()
{
    possible_buttons.push_back('8');
    possible_buttons.push_back('2');
    possible_buttons.push_back('4');
    possible_buttons.push_back('6');
    possible_buttons.push_back('a');
    possible_buttons.push_back('b');
    possible_buttons.push_back('c');

    input_map['8']=new DeviceButton(SDL_SCANCODE_W);
    input_map['2']=new DeviceButton(SDL_SCANCODE_S);
    input_map['4']=new DeviceButton(SDL_SCANCODE_A);
    input_map['6']=new DeviceButton(SDL_SCANCODE_D);

    input_map['a']=new DeviceButton(SDL_SCANCODE_U);
    input_map['b']=new DeviceButton(SDL_SCANCODE_I);
    input_map['c']=new DeviceButton(SDL_SCANCODE_O);

    for(int i=0;i<20;i++)
    {
        buffer.push_back(new Button('5'));
    }
}

InputManager::~InputManager()
{
    //dtor
}

bool InputManager::isPressed(Button button)
{
    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
    DeviceButton* device_button = input_map[button.value];
    if(device_button!=NULL)
    {
        if(currentKeyStates[device_button->sdl_scancode_key])
            return true;
        else
            return false;
    }
}

void InputManager::update()
{
//    for(list<Button*>::iterator i=buffer.begin();
//        i!=buffer.end();
//        i++)
//        cout<<(*i)->value;
//    cout<<endl;
//    cout.flush();

    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );

    bool is_button_pressed = false;
    for(int i=0;i<possible_buttons.size();i++)
    {
        if(isPressed(possible_buttons[i]))
        {
            buffer.push_back(new Button(possible_buttons[i]));
            buffer.pop_front();
            is_button_pressed=true;
            break;
        }
    }
    if(!is_button_pressed)
    {
        buffer.push_back(new Button('5'));
        buffer.pop_front();
    }
}

bool InputManager::isInBuffer(Move move)
{
    move.buttons;
    buffer;
    list<Button*>::iterator buffer_iterator=buffer.end();
    buffer_iterator--;

    for(int i=move.buttons.size()-1;i>=0;i--)
    {
        if((*buffer_iterator)->value!=move.buttons[i]->value)
        {
            return false;
        }
        buffer_iterator--;
    }
    return true;
}
