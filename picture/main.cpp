#include <graphics.h>
#include <iostream>
using namespace std;

class Point
{
private:
    int x, y;
public:
    Point()
    {
        x=0;
        y=0;
    }
    Point(int x1, int y1)
    {
        x=x1;
        y=y1;
    }

    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
};

class Shape
{
protected:
    int color;
public:
    Shape(){
       color=WHITE;
    }
    Shape(int c){
       color=c;
    }
};

class Line:public Shape
{
private:
    Point start;
    Point end;
public:
    Line() : start(), end(),Shape() {}
    Line(int x1, int y1, int x2, int y2,int c) : start(x1, y1), end(x2, y2), Shape(c){}

    void draw()
    {
        setcolor(color);
        line(start.getX(), start.getY(), end.getX(), end.getY());
    }
};

class Rect:public Shape
{
private:
    Point ul;
    Point lr;
public:
    Rect() : ul(), lr(),Shape() {}
    Rect(int x1, int y1, int x2, int y2,int c) : ul(x1, y1), lr(x2, y2),Shape(c) {}
    Rect(Point upperLeft, Point lowerRight,int c) : ul(upperLeft), lr(lowerRight),Shape(c){}

    void draw()
    {
        setcolor(color);
        rectangle(ul.getX(), ul.getY(), lr.getX(), lr.getY());
    }
};

class Circle:public Shape
{
private:
    Point center;
    int radius;
public:
    Circle() : center(),Shape()
    {
        radius=0;
    }
    Circle(int m, int n, int r,int c) : center(m, n),Shape(c)
    {
        radius=r;
    }

    void draw()
    {
        setcolor(color);
        circle(center.getX(), center.getY(), radius);
    }
};

class Picture
{
private:
    int cNum, rNum, lNum;
    Circle* pCircles;
    Rect* pRects;
    Line* pLines;

public:
    Picture()
    {
        cNum=0, rNum=0, lNum=0;
        pCircles=nullptr;
        pRects=nullptr;
        pLines=nullptr;
    }

    Picture(int cN, int rN, int lN,Circle* pC,Rect* pR, Line* pL)
    {
        cNum=cN, rNum=rN, lNum=lN;
        pCircles=pC;
        pRects=pR;
        pLines=pL;
    }


    void setCircles(int cn, Circle* pC)
    {
        cNum = cn;
        pCircles = pC;
    }

    void setRects(int rn, Rect* pR)
    {
        rNum = rn;
        pRects = pR;
    }

    void setLines(int ln, Line* pL)
    {
        lNum = ln;
        pLines = pL;
    }

    void paint()
    {
        for (int i = 0; i < cNum; i++)
        {
            pCircles[i].draw();
        }
        for (int i = 0; i < rNum; i++)
        {
            pRects[i].draw();
        }
        for (int i = 0; i < lNum; i++)
        {
            pLines[i].draw();
        }
    }
};

int main()
{
    // Initialize graphics mode
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    Picture myPic;

    Circle cArr[3] = { Circle(50, 50, 50,RED), Circle(200, 100, 100,GREEN), Circle(420, 50, 30,BLUE) };
    Line lArr[2] = { Line(420, 50, 300, 300,YELLOW), Line(40, 500, 500, 400,YELLOW) };
    Rect rArr[2];
    rArr[0] =Rect(30, 40, 170, 100,CYAN);
    Point p1(420, 50);
    Point p2(500, 300);
    rArr[1] =Rect(p1,p2,MAGENTA);

    myPic.setCircles(3, cArr);
    myPic.setRects(2, rArr);
    myPic.setLines(2, lArr);

    myPic.paint();

    getch();

    return 0;
}
