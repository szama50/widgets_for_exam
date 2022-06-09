#ifndef FUNBUTTON_HPP
#define FUNBUTTON_HPP

#include "widget.hpp"
#include "graphics.hpp"
#include <functional>
#include <string>

class FunButton : public Widget
{
private:
    std::string title;
    std::function<void()> f;
    bool focus;
public:
    FunButton(int,int,int,int,int,Application*,std::string,std::function<void()>);
    void draw() override;
    void event_handle(genv::event) override;
    std::string string_getter() override;
};

#endif // FUNBUTTON_HPP
