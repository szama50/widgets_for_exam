#ifndef MENU_H
#define MENU_H

#include "graphics.hpp"

#include "widget.hpp"

#include <vector>
#include <string>

class Menu : public Widget
{
private:
    std::vector<std::string> content;
    int number_of_visible_items;
    int current_item;
    int item_in_focus;
    int item_height;
    int from;
public:
    Menu(int,int,int,int,int,Application*,std::vector<std::string>,int);
    void draw() override;
    void event_handle(genv::event) override;
    std::string string_getter() override;
    void flip_items(int,int);
    void erase_item_string(int);
    void erase_item_totally(int);
    void add_item(std::string,int);
    double int_getter() override;
    std::vector<std::string> str_vector_getter() override;
    void str_vector_setter(std::vector<std::string>) override;
    void add_item_no_pos(std::string);
};

#endif // MENU_H
