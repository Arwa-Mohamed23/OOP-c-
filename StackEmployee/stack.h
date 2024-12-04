#ifndef STACK__H
#define STACK__H

#include "emp.h"

class Stack
{
private:
    int top;
    int size;
    Employee * emp ;
    static int counter;
public:
    Stack(int size);
    void push();
    Employee pop();
    void display();
    ~Stack();

};
#endif // STACK__H
