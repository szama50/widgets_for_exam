#include "funbutton.hpp"

#include <iostream>
using namespace std;
using namespace genv;

FunButton::FunButton(int x_,int y_,int size_x_,int size_y_,int frame_size_, Application* parent_,string title_,function<void()> f_)
    : Widget(x_,y_,size_x_,size_y_,frame_size_,parent_), title(title_),f(f_)
{
    focus = false;
}

void FunButton::draw()
{
    gout << color(255,255,255);
    gout << move_to(x,y);
    gout << box(size_x,size_y);
    if (focus)
        gout << color(76,76,76);
    else
        gout << color(0,0,0);
    gout << move_to(x+frame_size,y+frame_size);
    gout << box(size_x-2*frame_size,size_y-2*frame_size);
    gout << color(255,255,255);
    gout << move_to(x+0.5*(size_x-gout.twidth(title)),y+0.5*(size_y-gout.cascent()-gout.cdescent()));
    gout << text(title);
}

void FunButton::event_handle(event ev)
{
    focus = this->infocus(ev.pos_x,ev.pos_y);
    if (this->infocus(ev.pos_x,ev.pos_y) && ev.type == ev_mouse && ev.button == btn_left)
    {
        f();
    }
}

string FunButton::string_getter()
{
    return title;
}












