#include "menu.hpp"

using namespace std;
using namespace genv;

Menu::Menu(int x_, int y_, int size_x_,int size_y_,int frame_size_,Application* parent_, vector<string> content_,int number_of_visible_items_)
    : Widget(x_,y_,size_x_,size_y_,frame_size_,parent_),
    content(content_),number_of_visible_items(number_of_visible_items_)
{
    current_item = -1;
    item_in_focus = -1;
    item_height = (size_y_-2*frame_size_)/number_of_visible_items_;
    from = 0;
    while(content.size() < number_of_visible_items_)
    {
        content.push_back("");
    }
}

void Menu::draw()
{
    gout << color(155,155,155);
    gout << move_to(x,y);
    gout << box(size_x,size_y);
    gout << color(255,255,255);
    gout << move_to(x+frame_size,y+frame_size);
    gout << box(size_x-2*frame_size,size_y-2*frame_size);

    int k = -1;
    for (size_t i = from; i < from+number_of_visible_items; i++)
    {
        k++;
        gout << move_to(x+frame_size,y+frame_size+k*item_height);

        if (i == item_in_focus && i != current_item)
            gout << color(153,217,234);
        else if (i == current_item)
            gout << color(0,162,232);
        else
            gout << color(255,255,255);

        gout << box(size_x-2*frame_size,item_height);
        if (content.size()-1 >= i)
        {
            gout << color(0,0,0);
            gout << move_to(x+0.5*(size_x-gout.twidth(content[i])),y+k*item_height+frame_size+0.5*(item_height-gout.cascent()-gout.cdescent()));
            gout << text(content[i]);
        }
    }
    item_in_focus = -1;
}

void Menu::event_handle(event ev)
{
    while(content.size() < number_of_visible_items)
    {
        content.push_back("");
    }
    if (this->infocus(ev.pos_x,ev.pos_y))
    {

    if (ev.type == ev_mouse)
    {
        for (size_t i = 1; i < number_of_visible_items+1; i++)
        {
            if (ev.pos_y >= y+frame_size+(i-1)*item_height && ev.pos_y <= y+frame_size+i*item_height)
            {
                item_in_focus = from + (i-1);
                break;
            }
        }

        if (ev.button == btn_wheelup && from != 0)
            from--;
        else if (ev.button == btn_wheeldown && from != content.size()-number_of_visible_items)
            from++;
        else if (ev.button == btn_left && item_in_focus != -1)
            current_item = item_in_focus;
    }

    }
}

string Menu::string_getter()
{
    return content[current_item];
}

void Menu::flip_items(int item1, int item2)
{
    vector<string> temp = content;
    content[item1] = temp[item2];
    content[item2] = temp[item1];
    if (current_item == item1)
        current_item = item2;
    else if (current_item == item2)
        current_item = item1;
}

void Menu::erase_item_string(int item)
{
    if (item >= 0 && item < content.size())
        content[item] = "";
}

void Menu::erase_item_totally(int item)
{
    if (item >= 0 && item < content.size())
    {
        vector<string> temp;
        for (size_t i = 0; i < content.size(); i++)
            if ( i != item)
                temp.push_back(content[i]);
        content = temp;
    }
}

void Menu::add_item(string item,int item_pos)
{
    if (item_pos < 0 || item_pos > content.size())
        return;
    vector<string> temp;
    for (int i = 0; i < item_pos; i++)
        temp.push_back(content[i]);
    temp.push_back(item);
    for (size_t i = item_pos; i < content.size(); i++)
        temp.push_back(content[i]);
    if (item_pos == current_item)
        current_item++;
    content = temp;
}

double Menu::int_getter()
{
    return current_item;
}

vector<string> Menu::str_vector_getter()
{
    return content;
}

void Menu::str_vector_setter(vector<string> new_content)
{
    content = new_content;
}

void Menu::add_item_no_pos(string item)
{
    for (size_t i = 0; i < content.size(); i++)
        if (content[i] == "")
        {
            content[i] = item;
            return;
        }
    content.push_back(item);
    return;
}












