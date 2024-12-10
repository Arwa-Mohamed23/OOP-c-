#include <iostream>
using namespace std;

/*template <class T>
class List
{
private:
    int size;
    T * items ;
    T * temp;
public:

    List()
    {
        size=0;
        items=nullptr;
    }

    void push(T x)
    {
        this->size++;
        temp=new T[size] ;
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
        temp=new T[size-1] ;
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
        this->items=new T[size];
        for(int i=0; i<size; i++)
        {
            this->items[i]=s.items[i];
        }
    }

    ~List()
    {
        delete []items;
    }
};*/

class BaseType {
public:
    virtual void print()= 0;
};


template <class T>
class DerivedType : public BaseType {
private:
    T data;

public:
    DerivedType(T value){
       data=value;
    }

    void print(){
       cout << data << " ";
    }
};


class List {
private:
    int size;
    BaseType** items;

public:

    List()
    {
        size=0;
        items=nullptr;
    }

    ~List() {
        for (int i = 0; i < size; i++) {
            delete items[i];
        }
        delete[] items;
    }


    template <class T>
    void push(T value) {
        size++;
        BaseType** temp = new BaseType*[size];
        for (int i = 0; i < size-1; i++) {
            temp[i] = items[i];
        }
        temp[size-1] = new DerivedType<T>(value);
        delete[] items;
        items = temp;
    }

    int length(){
        return size;
    }


    void pop() {
        if (!size) {
            throw "List is empty";
        }
        BaseType** temp = new BaseType*[size - 1];
        for (int i = 0; i < size - 1; i++) {
            temp[i] = items[i];
        }
        delete[] items;
        items = temp;
        size--;
    }

    void display(){
        for (int i = 0; i < size; i++) {
            items[i]->print();
        }
    }
};

int main()
{

    List s;
    s.push(3);
    s.push(5.999);
    s.push('z');
    s.push("arwa");
    s.display();
    cout<<endl;
    s.pop();
    s.display();

    /*List <char>s;
    s.push('a');
    s.push('y');
    s.push('a');
    //s1=s;
    cout<<s.length()<<endl;
    s.display();
    s.pop();
    s.display();
    cout<<s.length()<<endl;
    //s1.display();*/


    return 0;
}
