#ifndef WIDGET_HPP
#define WIDGET_HPP

#include "graphics.hpp"
#include "application.hpp"
#include <string>

class Widget
{
protected:
    int x;
    int y;
    int size_x;
    int size_y;
    int frame_size;
    Application* parent;
public:
    Widget(int,int,int,int,int, Application*);
    bool infocus(int,int);

    //Virtual section
    virtual void draw() = 0;
    virtual void event_handle(genv::event) = 0;
    virtual double int_getter();
    virtual std::string string_getter();
    //Virtual section
};

#endif // WIDGET_HPP
