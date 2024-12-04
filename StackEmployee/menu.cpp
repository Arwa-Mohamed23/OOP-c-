#include "menu.h"
#include "terminalFunction.h"
#include <iostream>
#include <cstring>

using namespace std;

Menu::Menu(int length)
{
    this->length = length;
    currentoption = 0;
    items = new char*[length];
}

void Menu::setitem(char str[])
{
    if (currentoption >= length) {
        throw overflow_error("Stack is FULL!");
    }
    items[currentoption] = new char[strlen(str) + 1];
    strcpy(items[currentoption], str);
    currentoption++;
}

void Menu::display(int option)
{
    setTextColor(stdout,TC_WHITE);
    for (int i = 0; i < length; i++) {
        if (items[i] != nullptr) {
            if (i == option) {
                setTextColor(stdout,TC_BLUE);
                cout << items[i] << endl;
                setTextColor(stdout,TC_WHITE);
            } else {
                cout << items[i] << endl;
            }
        }
    }
}

Menu::~Menu()
{
    for (int i = 0; i < length; i++) {
        delete[] items[i];
    }
    delete[] items;
}

