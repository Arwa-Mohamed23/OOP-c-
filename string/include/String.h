#ifndef STRING_H
#define STRING_H


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
    String& operator= (String &s);
    //void operator<< (String &s);
    void print();
    ~String();
};

#endif // STRING_H
