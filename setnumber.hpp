#ifndef SETNUMBER_HPP
#define SETNUMBER_HPP

#include "graphics.hpp"

#include "widget.hpp"

class Setnumber : public Widget
{
private:
    int number;
    int interval_start;
    int interval_end;
    bool increase_infocus;
    bool decrease_infocus;
public:
    Setnumber(int,int,int,int,int,Application*,int,int,int);
    void draw() override;
    void event_handle(genv::event) override;
    double int_getter() override;
};

#endif // SETNUMBER_HPP
