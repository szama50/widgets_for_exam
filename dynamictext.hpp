#ifndef DYNAMICTEXT_HPP
#define DYNAMICTEXT_HPP

#include "widget.hpp"
#include "graphics.hpp"
#include <string>

class Dynamictext: public Widget
{
private:
    std::string content;
    int cursor_position;
    bool active;
public:
    Dynamictext(int,int,int,int,int,Application*,std::string);
    void draw() override;
    void event_handle(genv::event) override;
    std::string string_getter() override;
};

#endif // DYNAMICTEXT_HPP
