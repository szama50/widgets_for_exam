#include "application.hpp"
#include "menu.hpp"
#include "setnumber.hpp"
#include "statictext.hpp"
#include "dynamictext.hpp"
#include "checkbox2.hpp"
#include "funbutton.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

//For button testing
void print()
{
    cout << "You pushed the button!" << endl;
}
//For button testing

class App : public Application
{
private:
    Setnumber* sn;
    Setnumber* sn2;
    Menu* m;
    //Menu* m2;
    Statictext* st;
    Dynamictext* dt;
    Checkbox2* cb;
    FunButton* fb;
public:
    App(int window_width_,int window_height_): Application(window_width_,window_height_)
    {
        m = new Menu(100,100,300,500,5,this,
            {"item 1", "item 2", "item 3", "item 4", "item 5","item 6","item 7", "item 8", "item 9", "item 10", "item 11", "item 12"},10);
        //m2 = new Menu(500,100,300,500,5,this,
            //{"item 13", "item 14", "item 15", "item 16", "item 17","item 18","item 19", "item 20", "item 21", "item 22", "item 23", "item 24"},14);
        sn = new Setnumber(500,100,300,100,5,this,10,-20,20);
        st = new Statictext(500,300,300,100,5,this,"I am a static text widget. And also... I contain a really long text");
        dt = new Dynamictext(500,500,300,100,5,this,"I am a dynamic text. You can edit me if you want :)");
        cb = new Checkbox2(850,500,50,50,3,this,"X");
        fb = new FunButton(1000,500,200,100,5,this,"Button",[this](){check_checkbox(cb);});
        this->event_loop();
    }
    void erase_item_string_(Menu* m1,Setnumber* s1)
    {
        m1->erase_item_string(s1->int_getter());
    }
    void erase_item_totally_(Menu* m1,Setnumber* s1)
    {
        m1->erase_item_totally(s1->int_getter());
    }
    void flip_2_items(Menu* m1,int item1,int item2)
    {
        m1->flip_items(item1,item2);
    }
    void check_checkbox(Checkbox2* cb1)
    {
        cb1->check_negation();
    }
    void add_item(Dynamictext* dt1,Menu* m1,Setnumber* sn1)
    {
        m1->add_item(dt1->string_getter(),sn1->int_getter());
    }
    void to_file_string(string filename,Widget* w)
    {
        ofstream file;
        file.open(filename);
        file << w->string_getter() << '\n';
        file.close();
    }
    void to_file_int(string filename,Widget* w)
    {
        ofstream file;
        file.open(filename);
        file << w->int_getter() << '\n';
        file.close();
    }
    /*void change_item(Menu* from, Menu* to)
    {
        static int start = 14;
        if (from->string_getter() != "")
            to->add_item(from->string_getter(),start);
        from->erase_item_totally(from->int_getter());
        start++;
    }*/
};

int main()
{
    App* myApp = new App(1280,720);
    return 0;
}





