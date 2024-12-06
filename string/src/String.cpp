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
    *this=*this+src;
}

String& String::operator+ (String &s)
{
    char *temp=new char[size+s.size+1];
    for(int i=0; i<(size+s.size); i++)
    {
        if(i<size)
            temp[i]=this->str[i];
        else temp[i]=s.str[i-size];
    }
    temp[size+s.size]=TERMINATOR;
    delete[] this->str;
    this->str=temp;
    size=size+s.size;
    return *this;
}

void String::CopyStr (String src)
{
    *this=src;
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

int String::CompareStr (String src)
{
    for(int i=0; i<size&&i<src.size; i++)
    {
        if(this->str[i]>src.str[i])
            return 1;
        else if(this->str[i]<src.str[i])
            return -1;
    }
    if(size>src.size)return 1;
    else if(size<src.size)return -1;
    return 0;
}

char String::operator== (String &s)
{
    for(int i=0; i<size&&i<s.size; i++)
    {
        if(this->str[i]!=s.str[i])
            return 0;
    }
    if(size!=s.size)return 0;
    return 1;
}

ostream& operator<<(ostream& os,String &s)
{
    os<<s.str;
    return os;
}

void String::print()
{
    cout<<str;
}

String::~String()
{
    delete[] str;
}
