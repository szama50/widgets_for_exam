#ifndef STATICTEXT_HPP
#define STATICTEXT_HPP

#include "widget.hpp"
#include "graphics.hpp"
#include <string>

class Statictext : public Widget
{
private:
    std::string content;
public:
    Statictext(int,int,int,int,int,Application*,std::string);
    void draw() override;
    void event_handle(genv::event) override;
    std::string string_getter() override;
};

#endif // STATICTEXT_HPP
