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

    Circle cArr[5] = { Circle(230, 250, 50,BLUE),Circle(370, 250, 50,BLUE),
                       Circle(230, 250, 10,BLUE),Circle(370, 250, 10,BLUE),
                       Circle(300, 300, 200,BLUE)};
    Rect rArr(200, 350, 400, 400,BLUE);
    Line lArr[4] = { Line(240, 350, 240, 400,BLUE), Line(280, 350, 280, 400,BLUE),
                     Line(320, 350, 320, 400,BLUE), Line(360, 350, 360, 400,BLUE)};

    myPic.setCircles(5, cArr);
    myPic.setRects(1, &rArr);
    myPic.setLines(4, lArr);

    myPic.paint();

    getch();

    return 0;
}
