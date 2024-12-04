#include <iostream>
#include <limits>
#include "stack.h"
#include "menu.h"
#include "terminalFunction.h"

#define NUMOFLIST 3
#define EXTENDCHAR 27
#define UP 65
#define DOWN 66
#define ENTER 10
#define ARROW 91
#define BACK 127
#define HOME 68
#define END 67
#define PUSH 0
#define POP 1
#define DISPLAY 2

using namespace std;

int main()
{
    Menu m(NUMOFLIST);
    m.setitem("push");
    m.setitem("pop");
    m.setitem("Display");
    int size=0,option=0;
    cout<<"enter num of employee:";
    while(!isValidInteger(size)||size<=0)
    {
        cout<<"size not valid"<<endl;
        cout<<"enter num of employee:";
    }
    Stack empStak(size);
    char ch;
    system("clear");
    m.display(option);
    while(1)
    {
        ch=getch();
        if(ch==EXTENDCHAR)
        {
            ch=getch();
            if(ch==ARROW)
            {
                ch=getch();
                if(ch==DOWN)
                {
                    option=(option+1)%NUMOFLIST;
                }
                else if(ch==UP)
                {
                    option=(((option-1)%NUMOFLIST)+NUMOFLIST)%NUMOFLIST;
                }
                else if(ch==HOME)
                {
                    option=0;
                }
                else if(ch==END)
                {
                    option=NUMOFLIST-1;
                }
                system("clear");
                m.display(option);
            }
        }
        else if(ch==ENTER)
        {
            system("clear");
            if(option==PUSH)
            {
                try
                {
                    empStak.push();
                    cout<<"Data entered successfully"<<endl;
                }
                catch (const overflow_error& e)
                {
                    cout << e.what() << endl;
                }
                delay(1);
                system("clear");
                m.display(option);

            }
            else if(option==POP)
            {
                try
                {
                    empStak.pop().display();
                    cout<<"Data deleted successfully"<<endl;
                }
                catch (const underflow_error& e)
                {
                    cout << e.what() << endl;
                }
            }
            else if(option==DISPLAY)
            {
                try
                {
                    empStak.display();
                }
                catch (const underflow_error& e)
                {
                    cout << e.what() << endl;
                }

            }
        }
        else if(ch==BACK)
        {
            system("clear");
            m.display(option);
        }
    }


    return 0;
}
