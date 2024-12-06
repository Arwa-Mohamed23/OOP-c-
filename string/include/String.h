#ifndef STRING_H
#define STRING_H

#include <iostream>
using namespace std;

class String
{
private:
    int size;
    char *str;
public:
    String(char *str);
    String(String &s);
    int Length();
    void ConcatStr (String src);
    void CopyStr (String src);
    int CompareStr (String src);
    String& operator= (String &s);
    String& operator+ (String &s);
    char operator== (String &s);
    friend ostream& operator<<(ostream& os,String& s);
    void print();
    ~String();
};

#endif // STRING_H
