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
    ~ Complex(){
       cout<<"complex deleted....."<<endl;
    }
};
int main()
{
    Complex c(0.6);
    Complex c1;
    Complex c3(0.3,-9);
    c.display();
    c1.setComplex(-9,-8);
    c1.display();
    c3.display();
    return 0;
}
