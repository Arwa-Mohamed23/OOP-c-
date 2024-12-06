#include <iostream>

using namespace std;

class Complex
{
    double real;
    double imag;
public:
    Complex(){
      this->imag=0;
      this->real=0;
    }
    Complex(double real,double imag){
      this->real=real;
      this->imag=imag;
    }
    Complex(double data){
      this->real=data;
      this->imag=data;
    }

    void setComplex(double real, double imag)
    {
       this->real=real;
       this->imag=imag;
    }

    void setReal(double realdata)
    {
        real=realdata;
    }
    double getReal()
    {
        return real;
    }
    void setImag(double imgdata)
    {
        imag=imgdata;
    }
    double getImag()
    {
        return imag;
    }

    Complex add(Complex c)
    {
       Complex result;
        result.real=this->real+c.real;
        result.imag=this->imag+c.imag;
        return result;
    }

    Complex sub(Complex c)
    {
       Complex result;
        result.real=this->real-c.real;
        result.imag=this->imag-c.imag;
        return result;
    }

    Complex operator+(Complex c){
       Complex result;
        result.real=this->real+c.real;
        result.imag=this->imag+c.imag;
        return result;
    }

    Complex operator-(Complex c){
       Complex result;
        result.real=this->real-c.real;
        result.imag=this->imag-c.imag;
        return result;
    }

    Complex operator++(){//prefix
       this->real++;
       this->imag++;
       return *this;
    }

    Complex operator--(){
       this->real--;
       this->imag--;
       return *this;
    }

    Complex operator++(int x){//post
       Complex result;
       result.real=this->real;
       result.imag=this->imag;
       this->real++;
       this->imag++;
       return result;
    }

    Complex operator--(int x){//post
       Complex result=*this;
       //result.real=this->real;
       //result.imag=this->imag;
       this->real--;
       this->imag--;
       return result;
    }

    Complex operator+(int x){
       Complex result;
        result.real=this->real+x;
        result.imag=this->imag;
        return result;
    }

    Complex operator-(int x){
       Complex result;
        result.real=this->real-x;
        result.imag=this->imag;
        return result;
    }

    Complex operator+= (Complex c){
        this->real+=c.real;
        this->imag+=c.imag;
        return *this;
    }


    operator double(){
      return real;
    }

    int operator==(Complex c){
      if(this->real==c.real&&
         this->imag==c.imag)
         return 1;
         return 0;
    }

    void display()
    {
        if(!real && !imag)
            cout<<0;
        else
        {
            if(real)
            {
                cout<<real;
                if(imag>0)cout<<"+";
            }
            if(imag)
                cout<<imag<<"i";
        }
        cout<<endl;
    }
    friend Complex operator-(int x,Complex c);
    ~ Complex(){
       //cout<<"complex deleted....."<<endl;
    }
};

Complex operator+(int x,Complex c){
    Complex result;
    result.setReal(c.getReal()+x);
    result.setImag(c.getImag());
    return result;
}

Complex operator-(int x,Complex c){
       Complex result;
        result.real=x-c.real;
        result.imag=c.imag;
        return result;
    }
int main()
{
    Complex c(2.5,6);
    Complex c1(2,6);
    Complex c3;
    c.display();
    c1.display();
    //c3=c+c1;//c.operator+(c1)
    //c3=c-c1;
    //++c;
    //--c;
    //c3=c++; //c.operator++(45565)
    //c3=c--;
    //c3=c-5;
    //c3=5-c;
    //cout<<(double)c;
    //c+=c1;
    //c.display();
    if(c==c1){
      cout<<"yes";
    }else{
      cout<<"no";
    }
    return 0;
}
