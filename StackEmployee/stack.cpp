#include "stack.h"
#include <iostream>
#include "emp.h"

using namespace std;

int Stack::counter=0;

Stack::Stack(int size)
{
    counter++;
    this->size=size;
    top=0;
    emp= new Employee[size];
}


void Stack::push()
{
    if(top==size)
    {
        throw overflow_error("Stack is FULL!");
    }
    emp[top++].enterNewEmployee();
}

Employee Stack::pop()
{
    if(!top)
    {
        throw underflow_error("Stack is empty!");
    }
    return emp[--top];
}

void Stack::display()
{
    cout<<"stack "<<counter<<endl;
    if(!top)
    {
        throw underflow_error("Stack is empty!");
    }
    for(int i=top-1; i>=0; i--)
    {
        emp[i].display();
    }
}

Stack::~Stack()
{
    counter--;
    delete []emp;
}


