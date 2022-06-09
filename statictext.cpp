#include "statictext.hpp"

using namespace std;
using namespace genv;

Statictext::Statictext(int x_, int y_, int size_x_,int size_y_,int frame_size_,Application* parent_,string content_)
 : Widget(x_,y_,size_x_,size_y_,frame_size_,parent_), content(content_)
{}

string visible_chars(string content, int size_x, int frame_size)
{
    int counter = 0;
    string chars = "";
    while (gout.twidth(chars+'W') < size_x - 2* frame_size && counter < content.size())
    {
        chars += content[counter];
        counter++;
    }
    return chars;
}

void Statictext::draw()
{
    gout << color(255,255,255);
    gout << move_to(x,y);
    gout << box(size_x,size_y);
    gout << color(0,0,0);
    gout << move_to(x+frame_size,y+frame_size);
    gout << box(size_x-2*frame_size,size_y-2*frame_size);
    gout << color(255,255,255);
    string visible_characters = visible_chars(content,size_x,frame_size);
    gout << move_to(x+0.5*(size_x-gout.twidth(visible_characters)),y+0.5*(size_y-gout.cascent()-gout.cdescent()));
    gout << text(visible_characters);
}

void Statictext::event_handle(event)
{
    return;
}

string Statictext::string_getter()
{
    return content;
}




