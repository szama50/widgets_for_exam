#include "dynamictext.hpp"

#include <iostream>

using namespace genv;
using namespace std;

Dynamictext::Dynamictext(int x_, int y_, int size_x_,int size_y_,int frame_size_,Application* parent_, string content_)
    :Widget(x_,y_,size_x_,size_y_,frame_size_, parent_)
{
    active = false;
    cursor_position = 0;
    content = '|'+content_;
}

string visible_chars_(string content, int size_x, int frame_size, int cursor_position)
{
    string temp = "";
    int j = 0;
    while (gout.twidth(temp) < 0.85*size_x && j < content.size())
    {
        temp+=content[j];
        j++;
    }
    string chars = "";
    if (temp.size() == content.size())
        return temp;
    else if (cursor_position > temp.size())
    for (int i = cursor_position - temp.size(); i <= cursor_position; i++)
        chars+=content[i];
    else
    for (size_t i = 0; i < temp.size(); i++)
        chars+=content[i];
    return chars;
}

void Dynamictext::draw()
{
    gout << color(255,255,255);
    gout << move_to(x,y);
    gout << box(size_x,size_y);
    gout << color(0,0,0);
    gout << move_to(x+frame_size,y+frame_size);
    gout << box(size_x-2*frame_size,size_y-2*frame_size);
    gout << color(255,255,255);
    string visible_characters = visible_chars_(content,size_x,frame_size,cursor_position);
    gout << move_to(x+0.5*(size_x-gout.twidth(visible_characters)),y+0.5*(size_y-gout.cascent()-gout.cdescent()));
    gout << text(visible_characters);
}

string move_cursor_right(string content, int cursor_position)
{
    string temp = "";
    for (int i = 0; i < cursor_position; i++)
        temp+=content[i];
    temp+=content[cursor_position+1];
    temp+='|';
    for (size_t i = cursor_position+2; i < content.size(); i++)
        temp+=content[i];
    return temp;
}

string move_cursor_left(string content,int cursor_position)
{
    string temp = "";
    for (int i = 0; i < cursor_position - 1; i++)
        temp+= content[i];
    temp+='|';
    temp+=content[cursor_position-1];
    for (int i = cursor_position+1; i < content.size(); i++)
        temp+=content[i];
    return temp;
}

string delete_char(string content,int cursor_position)
{
    string temp = "";
    for (size_t i = 0; i < content.size(); i++)
        if (i != cursor_position - 1)
            temp+=content[i];
    return temp;
}

string add_char(string content, int cursor_position, int character)
{
    string temp = "";
    for (int i = 0; i < cursor_position; i++)
        temp+=content[i];
    temp+=char(character);
    temp+='|';
    for (size_t i = cursor_position+1; i < content.size(); i++)
        temp+=content[i];
    return temp;
}

void Dynamictext::event_handle(event ev)
{
    if (ev.type == ev_mouse && ev.button == btn_left)
    {
        if (this->infocus(ev.pos_x,ev.pos_y))
            active = true;
        else
            active = false;
    }
    if (active)
    {
        if (ev.type == ev_key)
        {
            if (ev.keycode == key_right && cursor_position != content.size()-1)
            {
                content = move_cursor_right(content,cursor_position);
                cursor_position++;
            }
            if (ev.keycode == key_left && cursor_position != 0)
            {
                content = move_cursor_left(content,cursor_position);
                cursor_position--;
            }
            if (ev.keycode == key_backspace && cursor_position != 0)
            {
                content = delete_char(content,cursor_position);
                cursor_position--;
            }
            if (ev.keycode > 0 && ev.keycode != key_capsl && ev.keycode != key_right && ev.keycode != key_left && ev.keycode != key_backspace &&
                ev.keycode != key_lshift && ev.keycode != key_delete && ev.keycode != key_down && ev.keycode != key_up && ev.keycode != key_lctrl)
            {
                content = add_char(content,cursor_position,ev.keycode);
                cursor_position++;
                this->draw();
            }
        }
    }
}

string Dynamictext::string_getter()
{
    string temp = "";
    for (size_t i = 0; i < content.size(); i++)
        if (i != cursor_position)
            temp+=content[i];
    return temp;
}









