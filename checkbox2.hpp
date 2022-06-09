#ifndef CHECKBOX_HPP
#define CHECKBOX_HPP

#include "widget.hpp"
#include "graphics.hpp"
#include <string>

class Checkbox2 : public Widget
{
private:
    bool checked;
    std::string mark;
public:
    Checkbox2(int,int,int,int,int,Application*,std::string);
    void draw() override;
    void event_handle(genv::event) override;
    std::string string_getter() override;
    double int_getter() override;
    void check_negation();
};

#endif // CHECKBOX_HPP
