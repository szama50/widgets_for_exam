#include "application.hpp"
#include "widget.hpp"

#include <iostream>

using namespace genv;
using namespace std;

Application::Application(int window_width_, int window_height_) : window_width(window_width_), window_height(window_height_)
{
    gout.open(window_width,window_height);
    gout.load_font("LiberationSans-Regular.ttf",20);
    gout << refresh;
}

void Application::clearscreen()
{
    gout << color(0,0,0);
    gout << move_to(0,0);
    gout << box(window_width,window_height);
}

void Application::event_loop()
{
    for (size_t i = 0; i < widgets.size(); i++)
        widgets[i]->draw();
    gout << refresh;
    event ev;
    while(gin >> ev && ev.keycode != key_escape)
    {
        for (Widget* w : widgets)
            w->draw();
        for (Widget* w : widgets)
            w->event_handle(ev);
        gout << refresh;
    }
}

void Application::register_widget(Widget* w)
{
    widgets.push_back(w);
}




