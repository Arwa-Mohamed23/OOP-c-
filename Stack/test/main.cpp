#include <iostream>

using namespace std;

template <class T>
class jump{
   T a;
};
int main()
{
   //jump e[2];
    jump<int> *j=new jump<int> [2];
    return 0;
}
