#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "graphics.hpp"
#include <vector>

class Widget;

class Application
{
protected:
    int window_width;
    int window_height;
    std::vector<Widget*> widgets;
public:
    Application(int,int);
    void clearscreen();
    void event_loop();
    void register_widget(Widget*);
};

#endif // APPLICATION_HPP
