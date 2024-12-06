#include <iostream>
using namespace std;

class List
{
private:
    int size;
    int * items ;
    int * temp;
public:

    List()
    {
        size=0;
        items=nullptr;
    }

    void push(int x)
    {
        this->size++;
        temp=new int[size] ;
        for(int i=0;i<size-1;i++){
          temp[i]=items[i];
        }
        temp[size-1]=x;
        delete []items;
        items=temp;
    }

    int length(){
      return size;
    }

    void pop()
    {
        if(!size)
        {
            throw underflow_error("list is empty!");
        }
        temp=new int[size-1] ;
        for(int i=0;i<size-1;i++){
          temp[i]=items[i];
        }
        delete []items;
        items=temp;
        this->size--;
    }

    void display()
    {
        if(!size)
        {
            throw underflow_error("list is empty!");
        }
        for(int i=0; i<size; i++)
        {
            cout<<items[i]<<" ";
        }
        cout<<endl;
    }

    void operator= (List &s)
    {
        delete[] this->items;
        this->size=s.size;
        this->items=new int[size];
        for(int i=0; i<size; i++)
        {
            this->items[i]=s.items[i];
        }
    }

    ~List()
    {
        delete []items;
    }
};


int main()
{
    List s,s1;
    s.push(2);
    s.push(3);
    s.push(4);
    //s1=s;
    cout<<s.length()<<endl;
    s.display();
    s.pop();
    s.display();
    cout<<s.length()<<endl;
    //s1.display();
    return 0;
}
