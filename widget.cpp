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

std::vector<std::string> Widget::str_vector_getter()
{
    return {};
}

std::vector<int> Widget::int_vector_getter()
{
    return {};
}

void Widget::string_setter(std::string)
{
    return;
}

void Widget::int_setter(int)
{
    return;
}

void Widget::str_vector_setter(std::vector<std::string>)
{
    return;
}

void Widget::int_vector_setter(std::vector<int>)
{
    return;
}





