#include <iostream>

using namespace std;

/*void swapAddress(int *ptr1,int *ptr2){
   int temp=*ptr1;
   *ptr1=*ptr2;
   *ptr2=temp;
}*/

/*void swapRefrence(int &ptr1,int &ptr2){
   int temp=ptr1;
   ptr1=ptr2;
   ptr2=temp;
}*/

void swapValue(int ptr1,int ptr2){
   int temp=ptr1;
   ptr1=ptr2;
   ptr2=temp;
   cout<<"after swap in function x= "<<ptr1<<", y= "<<ptr2<<endl;
}
int main()
{
    int x=0,y=0;
    cout<<"Enter x: ";
    cin>>x;
    cout<<"Enter y: ";
    cin>>y;
    cout<<"before swap x= "<<x<<", y= "<<y<<endl;
    //swapAddress(&x,&y);
    //swapRefrence(x,y);
    swapValue(x,y);
    cout<<"after swap x= "<<x<<", y= "<<y<<endl;
    return 0;
}
