#include "checkbox2.hpp"
#include <string>

using namespace std;
using namespace genv;

Checkbox2::Checkbox2(int x_, int y_, int size_x_,int size_y_,int frame_size_,Application* parent_,string mark_)
    :Widget(x_,y_,size_x_,size_y_,frame_size_, parent_), mark(mark_)
{
    checked = false;
}

void Checkbox2::draw()
{
    gout << color(255,255,255);
    gout << move_to(x,y);
    gout << box(size_x,size_y);
    gout << color(0,0,0);
    gout << move_to(x+frame_size,y+frame_size);
    gout << box(size_x-2*frame_size,size_y-2*frame_size);
    if (checked)
    {
        gout << color(255,255,255);
        gout << move_to(x+0.5*(size_x-gout.twidth(mark)),y+0.5*(size_y-gout.cascent()-gout.cdescent()));
        gout << text(mark);
    }
}

void Checkbox2::event_handle(event ev)
{
    if (this->infocus(ev.pos_x,ev.pos_y) && ev.type == ev_mouse && ev.button == btn_left)
        checked = !checked;
}

string Checkbox2::string_getter()
{
    return mark;
}

double Checkbox2::int_getter() //for bool values
{
    return checked;
}

void Checkbox2::check_negation()
{
    checked = !checked;
}








