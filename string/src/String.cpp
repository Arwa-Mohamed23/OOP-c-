#include <iostream>
#include "String.h"

using namespace std;
#define TERMINATOR '\0'

String::String(char *str)
{
    size=0;
    while(str[size]!=TERMINATOR)
    {
        size++;
    }
    this->str =new char[size+1];
    for(int i=0; i<size; i++)
        this->str[i]=str[i];
    this->str[size]=TERMINATOR;
}

String::String(String &s)
{
    size=s.size;
    this->str=new char[size+1];
    for(int i=0; i<size; i++)
    {
        this->str[i]=s.str[i];
    }
    this->str[size]=TERMINATOR;
}

int String::Length()
{
    return size;
}

void String::ConcatStr (String src)
{
    char *temp=new char[size+src.size+1];
    for(int i=0; i<(size+src.size); i++)
    {
        if(i<size)
            temp[i]=this->str[i];
        else temp[i]=src.str[i-size];
    }
    temp[size+src.size]=TERMINATOR;
    delete[] this->str;
    this->str=temp;
    size=size+src.size;
}

void String::CopyStr (String src)
{
    delete[] this->str;
    size=src.size;
    this->str=new char[size+1];
    for(int i=0; i<size; i++)
    {
        this->str[i]=src.str[i];
    }
    this->str[size]=TERMINATOR;
}

String& String::operator= (String &s)
{
    if(this != &s)
    {
        delete[] this->str;
        this->size=s.size;
        this->str=new char[size+1];
        for(int i=0; i<size; i++)
        {
            this->str[i]=s.str[i];
        }
        this->str[size]=TERMINATOR;
    }
    return *this;
}

/*void String::operator<< (String &s)
{
    cout<<s.str;
}*/

void String::print()
{
    cout<<str;
}

String::~String()
{
    delete[] str;
}
