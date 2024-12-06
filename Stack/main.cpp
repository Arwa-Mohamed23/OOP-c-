#include <iostream>
using namespace std;

class Stack
{
private:
    int top;
    int size;
    int * items ;
    static int counter;
public:

    Stack(int size)
    {
        counter++;
        this->size=size;
        top=0;
        items= new int[size];
    }

    Stack(Stack &x)
    {
        counter++;
        this->size=x.size;
        this->top=x.top;
        this->items= new int[size];
        for(int i=0; i<top; i++)
        {
            this->items[i]=x.items[i];
        }
    }

    static int getCounter()
    {
        return counter;
    }

    void push(int x)
    {
        if(top==size)
        {
            throw overflow_error("Stack is FULL!");
        }
        items[top++]=x;
    }

    int pop()
    {
        if(!top)
        {
            throw underflow_error("Stack is empty!");
        }
        return items[--top];
    }

    void display()
    {
        if(!top)
        {
            throw underflow_error("Stack is empty!");
        }
        for(int i=top-1; i>=0; i--)
        {
            cout<<items[i]<<" ";
        }
        cout<<endl;
    }

    void operator= (Stack &s)
    {
        delete[] this->items;
        this->size=s.size;
        this->top=s.top;
        this->items=new int[size];
        for(int i=0; i<top; i++)
        {
            this->items[i]=s.items[i];
        }
    }

    static void viewcontent(Stack &s)
    {
        int i=s.top-1;
        while(i>=0)
        {
            cout<<s.items[i--]<<" ";
        }
        cout<<endl;
    }

    ~Stack()
    {
        counter--;
        delete []items;
    }
};


int Stack::counter=0;
int main()
{
    Stack s(3);
    s.push(1);
    s.push(2);
    s.push(3);
    Stack s2(s);
    //s2=s;
    s.display();
    s2.display();
    s.pop();
    Stack::viewcontent(s);
    Stack::viewcontent(s2);
    //cout<<Stack::getCounter()<<endl;
    return 0;
}