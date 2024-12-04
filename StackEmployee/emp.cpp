#include "emp.h"
#include "terminalFunction.h"
#include <iostream>
#include <limits>
using namespace std;

bool isValidInteger(int& output)
{
    cin >> output;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return true;
}

void Employee::enterNewEmployee ()
{
    cout<<"Enter employee code: ";
    while(!isValidInteger(code)||code<=0)
    {
        cout<<"code not valid"<<endl;
         cout<<"Enter employee code: ";
    }
    this->code=code;
    cout<<"Enter employee name: ";
    cin>>this->name;
    cout<<"Enter employee salary: ";
     while(!isValidInteger(salary)||salary<0)
    {
        cout<<"salary not valid"<<endl;
         cout<<"Enter employee salary: ";
    }
    this->salary=salary;
}

void Employee::display()
{
    cout<<"Employee code: "<<this->code<<endl;
    cout<<"Employee name: "<<this->name<<endl;
    cout<<"Employee salary: "<<this->salary<<endl;
    cout<<"***************************************\n";
}
