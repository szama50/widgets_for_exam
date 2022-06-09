#include "setnumber.hpp"

#include <string>
#include <iostream>

using namespace std;
using namespace genv;

Setnumber::Setnumber(int x_,int y_,int size_x_,int size_y_,int frame_size_,Application* parent_,int number_, int interval_start_, int interval_end_)
    : Widget(x_,y_,size_x_,size_y_,frame_size_, parent_), number(number_), interval_start(interval_start_), interval_end(interval_end_)
{
    increase_infocus = false;
    decrease_infocus = false;
}

canvas button_generator(int size_, bool up, bool focused)
{
    canvas button;
    button.open(size_,size_);
    if (focused)
        button << color(153,217,234);
    else
        button << color(255,255,255);
    button << move_to(0,0);
    button << box(size_,size_);

    int from, to;
    if (up)
    {
        from = int(0.75*size_);
        to = int(0.25*size_);
    }
    else
    {
        from = int(0.25*size_);
        to = int(0.75*size_);
    }


    button << color(155,155,155);
    for (int i = int(0.25*size_); i < int(0.75*size_); i++)
    {
        button << move_to(i,from);
        button << line_to(int(0.5*size_),to);
    }
    return button;
}

void Setnumber::draw()
{
    //Frame
    gout << color(155,155,155);
    gout << move_to(x,y);
    gout << box(size_x,size_y);
    gout << color(255,255,255);
    gout << move_to(x+frame_size,y+frame_size);
    gout << box(size_x-2*frame_size,size_y-2*frame_size);
    //Frame

    //Buttons
    canvas increase_button = button_generator(0.5*size_y-frame_size,true, increase_infocus);
    canvas decrease_button = button_generator(0.5*size_y-frame_size,false, decrease_infocus);
    gout << stamp(increase_button,x+size_x-0.5*size_y,y+frame_size);
    gout << stamp(decrease_button,x+size_x-0.5*size_y,y+0.5*size_y);
    //Buttons

    //Number
    gout << color(0,0,0);
    gout << move_to(x+0.5*(size_x-gout.twidth(to_string(number))),y+0.5*(size_y-gout.cascent()-gout.cdescent()));
    gout << text(to_string(number));
    //Number

    increase_infocus = false;
    decrease_infocus = false;
}

void Setnumber::event_handle(event ev)
{
    static int last_x_pos = -1;
    static int last_y_pos = -1;
    if (ev.type == ev_mouse)
    {
        last_x_pos = ev.pos_x;
        last_y_pos = ev.pos_y;
    }
    if (this->infocus(ev.pos_x,ev.pos_y) && ev.type == ev_mouse)
    {
        bool logical = (x+size_x-0.5*size_y+frame_size <= ev.pos_x && ev.pos_x <= x+size_x-frame_size);
        increase_infocus = (logical && ev.pos_y >= y+frame_size && ev.pos_y <= y+0.5*size_y);
        decrease_infocus = (logical && ev.pos_y >= y+0.5*size_y && ev.pos_y <= y+size_y-frame_size);

        if (ev.button == btn_left)
        {
            if (increase_infocus && interval_end > number)
                number++;
            if (decrease_infocus && interval_start < number)
                number--;
        }
    }
    if (this->infocus(last_x_pos,last_y_pos) && ev.type == ev_key)
    {
        if (ev.keycode == key_up && interval_end > number)
            number++;
        else if (ev.keycode == key_down && interval_start < number)
            number--;
        else if (ev.keycode == 97 && number+10 <= interval_end)
            number+=10;
        else if (ev.keycode == 91 && number-10 >= interval_start)
            number-=10;
    }
}

double Setnumber::int_getter()
{
    return number;
}








