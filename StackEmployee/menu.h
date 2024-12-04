#ifndef MENU__H
#define MENU__H


class Menu
{
private:
    int currentoption;
    int length;
    char ** items;
public:
    Menu(int length);
    void setitem(char str[]);
    void display(int option);
    ~Menu();

};
#endif
