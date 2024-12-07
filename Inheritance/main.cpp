#include <iostream>

using namespace std;

class Base{
    private:
    protected:
    int a,b;

    public :
    Base(){
        a=0,b=0;
        cout<<"Base Constructor \n";
    }
    Base(int a , int b){
        this->a=a;
        this->b=b;
        cout<<"Base Parameter Constructor \n";
    }

    int sum(){
        cout<<"Base Sum \n";
        return a+b;
    }
    ~Base(){
        cout<<"Base Destructor \n";
    }
};

class Derived:public Base{
    private:
    int c;
    protected:

    public :
    Derived(){
        c=0;
        cout<<"Derived Constructor \n";
    }
    Derived(int a, int b,int c):Base(a,b){
        this ->c =c;
        cout<<"Derived Parameter Constructor \n";
    }

    int get_c(){
        return c;
    }

    int sum(){
        cout<<"Derived Sum  \n";
        return Base::sum()+c;
    }

    void display(){
        cout<<"a = "<<a<<" b = "<<b <<" c = "<<c<<endl;
    }

    ~Derived(){
        cout<<"Derived Destructor \n";
    }

};

class SecondDerived:public Derived{
    private:
    int d;
    public :
    SecondDerived(){
         d=0;
        cout<<"SecondDerived Constructor \n";
    }
    SecondDerived(int a, int b,int c,int d):Derived(a,b,c){
        this ->d =d;
        cout<<"SecondDerived Parameter Constructor \n";
    }
    int sum3(){
        return a+b+get_c()+d;
    }
    void display2(){
        cout<<"a = "<<a<<" b = "<<b <<" c = "<<get_c()<<" d = "<<d<<endl;
    }
    ~SecondDerived(){
        cout<<"SecondDerived Destructor \n";
    }

};

void printsum(Base &b){
    cout<<b.sum()<<endl;
}


int main()
{

    Derived d(1,2,3);
    //d.display();

    /*SecondDerived d2(1,2,3,5);
    d2.display2();*/

    Base *ptr=&d;

    //cout<<d.sum()<<endl;
    //cout<<d.Base::sum()<<endl;
    //cout<<ptr->sum()<<endl;
    //printsum(*ptr);
    //printsum(d);

    /*Base b(1,2);
    printsum(b);*/
    return 0;
}
