#include "widget.hpp"

Widget::Widget(int x_, int y_, int size_x_,int size_y_,int frame_size_, Application* parent_) : x(x_), y(y_), size_x(size_x_), size_y(size_y_),
    frame_size(frame_size_), parent(parent_)
{
    parent->register_widget(this);
}

bool Widget::infocus(int mouse_x,int mouse_y)
{
    return (mouse_x >= x && mouse_x <= x+size_x && mouse_y >= y && mouse_y <= y+size_y);
}

std::string Widget::string_getter()
{
    return "";
}

double Widget::int_getter()
{
    return 0.1;
}
