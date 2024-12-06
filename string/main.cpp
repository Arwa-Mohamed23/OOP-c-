#include <iostream>
#include "String.h"

using namespace std;

int main()
{
    String s("arwa");
    String a("aya");
    String b("mona");
    s.print();
    cout<<endl;
    cout<<s.Length()<<endl;
    //s.ConcatStr(a);
    s.CopyStr(a);
    //s=a=b;
    /*s.print();
    cout<<endl;*/
    //cout<<a<<endl;
    cout<<s.Length()<<endl;
    return 0;
}
