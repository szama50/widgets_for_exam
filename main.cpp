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

template<typename T>
vector<T> erase_item_from_vector(vector<T> original, int index_to_delete)
{
    vector<T> updated = {};
    for (size_t u = 0; u < original.size(); u++)
        if (u != index_to_delete)
            updated.push_back(original[u]);
    return updated;
}

class App : public Application
{
private:
    Setnumber* sn;
    Setnumber* sn2;
    Menu* m;
    Menu* m2;
    Statictext* st;
    Dynamictext* dt;
    Checkbox2* cb;
    //FunButton* fb0;
    FunButton* fb;
    //FunButton* fb2;
    /*int free_space;
    vector<int> numbers_in_first;
    vector<int> numbers_in_second;*/
public:
    App(int window_width_,int window_height_): Application(window_width_,window_height_)
    {
        m = new Menu(10,10,250,400,5,this,
            {},10);
        m2 = new Menu(350,10,250,400,5,this,
            {},10);
        sn = new Setnumber(1000,10,250,70,5,this,10,1,25);
        st = new Statictext(650,100,300,70,5,this,"Amount of free space: 25");
        dt = new Dynamictext(650,10,300,70,5,this,"Item");
        //cb = new Checkbox2(850,500,50,50,3,this,"X");
        //fb0 = new FunButton(1000,100,170,70,5,this,"Add item",[this](){add_item(m,m2,dt,sn,st);});
        //fb = new FunButton(650,200,170,70,5,this,"Delete 1",[this](){delete_item(m,m2,st);});
        //fb2 = new FunButton(900,200,170,70,5,this,"Delete 2",[this](){delete_item_simply(m2);});
        /*free_space = 25;
        numbers_in_first = {};
        numbers_in_second = {};*/
        this->event_loop();
    }
};

int main()
{
    App* myApp = new App(1280,720);
    return 0;
}


//Struct Menu operation
//Struct Menu operation


//Non_struct Menu operation




    //Menu with capacity
    /*void change_static(Statictext* static1)
    {
        static1->string_setter("Amount of free space: " + to_string(free_space));
    }
    void add_item(Menu* menu1, Menu* menu2, Dynamictext* dynamic1, Setnumber* setnumber1, Statictext* static1)
    {
        if (free_space >= int(setnumber1->int_getter()))
        {
            menu1->add_item_no_pos(dynamic1->string_getter() + " (" + to_string(int(setnumber1->int_getter())) + ')');
            numbers_in_first.push_back(int(setnumber1->int_getter()));
            free_space-=int(setnumber1->int_getter());
        }
        else
        {
            menu2->add_item_no_pos(dynamic1->string_getter() + " (" + to_string(int(setnumber1->int_getter())) + ')');
            numbers_in_second.push_back(int(setnumber1->int_getter()));
        }
        this->change_static(static1);
    }
    void delete_item_simply(Menu* menu1)
    {
        if (int(menu1->int_getter() != -1))
        {
            erase_item_from_vector(numbers_in_second,int(menu1->int_getter()));
            menu1->erase_item_totally(int(menu1->int_getter()));
        }
    }
    void delete_item(Menu* menu1, Menu* menu2, Statictext* static1)
    {
        if (int(menu1->int_getter() != -1) && menu1->str_vector_getter()[int(menu1->int_getter())] != "")
        {
            free_space+=numbers_in_first[int(menu1->int_getter())];
            numbers_in_first = erase_item_from_vector(numbers_in_first,int(menu1->int_getter()));
            menu1->erase_item_totally(int(menu1->int_getter()));

            vector<int> indexes_to_be_deleted = {};
            for (size_t i = 0; i < numbers_in_second.size(); i++)
            {
                if (numbers_in_second[i] <= free_space)
                {
                    indexes_to_be_deleted.push_back(i);
                    free_space-=numbers_in_second[i];
                }
            }

            for (size_t i = 0; i < indexes_to_be_deleted.size(); i++)
            {
                menu1->add_item_no_pos(menu2->str_vector_getter()[indexes_to_be_deleted[i]]);
                numbers_in_first.push_back(numbers_in_second[indexes_to_be_deleted[i]]);
            }

            vector<int> copy_indexes = indexes_to_be_deleted;
            for (size_t i = 0; i < copy_indexes.size(); i++)
            {
                numbers_in_second = erase_item_from_vector(numbers_in_second,copy_indexes[i]);
                for (size_t j = 0; j < copy_indexes.size(); j++)
                    copy_indexes[j]--;
            }

            for (size_t i = 0; i < indexes_to_be_deleted.size(); i++)
            {
                menu2->erase_item_totally(indexes_to_be_deleted[i]);
                for (size_t j = 0; j < indexes_to_be_deleted.size(); j++)
                    indexes_to_be_deleted[j]--;
            }

            this->change_static(static1);
        }
    }*/

//Non_struct Menu operation









