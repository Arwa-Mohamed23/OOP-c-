#include <iostream>

using namespace std;

class Shape
{
protected:
    float d1;
    float d2;
public:
    Shape()
    {
        d1=0;
        d2=0;
    }

    Shape(float x)
    {
        d1=x;
        d2=x;
    }

    Shape(float x, float y)
    {
        d1=x;
        d2=y;
    }

    void setDim1(float x){
       d1=x;
    }
    void setDim2(float y){
       d2=y;
    }

    float getDim1(){
       return d1;
    }

    float getDim2(){
       return d2;
    }

    virtual float calculateArea()=0;
};

class Triangle:public Shape
{
public:
    Triangle (float b,float h):Shape(b,h) {}
    float calculateArea()
    {
        return 0.5*d1*d2;
    }
};

class Rectangle:public Shape
{
public:
    Rectangle (float d1,float d2):Shape(d1,d2) {}
    Rectangle ():Shape() {}
    float calculateArea()
    {
        return d1*d2;
    }
};

class Square:private Rectangle
{
public:
    Square (float d1):Rectangle(d1,d1){}

    void setSquareDim(float d1){
        setDim1(d1);
    }

    float getSquareDim(){
       return getDim1();
    }

     float calculateArea()
    {
        return Rectangle::calculateArea();
    }
};

class Circle:private Shape
{
public:
    Circle (float r):Shape(r) {}

    void setRadius(float r){
        setDim1(r);
    }

    float getRadius(){
       return getDim1();
    }
    float calculateArea()
    {
        return (22.0/7)*d1*d2;
    }
};

int main()
{
   /* Rectangle r;
    r.setDim1(3);
    r.setDim2(5);
    cout<<r.calculateArea()<<endl;

    Triangle t(4,5);
    cout<<t.getDim1()<<endl;
    cout<<t.calculateArea()<<endl;*/

    /*Circle c(5);
    cout<<c.calculateArea()<<endl;
    c.setRadius(4);
    cout<<c.getRadius()<<endl;*/

    Square sq(5);
    cout<<sq.calculateArea()<<endl;
    sq.setSquareDim(3);
    cout<<sq.getSquareDim()<<endl;

    return 0;
}
