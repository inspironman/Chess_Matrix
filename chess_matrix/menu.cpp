#include <iostream>
#include "menu.h"
#include <sstream>
#define menuCount 6 ///number of menu items

using namespace std;

///Check if the given menuitem number exists
bool check(int a){return a>=0 && a<=menuCount;}

void Menu::run()
{
    int n = 0;
    do
    {
        menuWrite();
        cout << endl << ">>>>" ;
        cin >> n;
        switch(n)
        {
        case 1:
            get();
            break;
        case 2:
            set();
            break;
        case 3:
            read();
            break;
        case 4:
            write();
            break;
        case 5:
            sum();
            break;
        case 6:
            mul();
            break;
        default:
            cout<<"\nGoodbye!\n";
            break;
        }
    }
    while(n!=0);
}

void Menu::menuWrite()
{
    cout << endl << endl;
    cout<<"Please only enter integer Values "<<endl;
    cout << " 0. - Quit" << endl;
    cout << " 1. - Get an element of the matrix" << endl;
    cout << " 2. - Overwrite an element of the matrix" << endl;
    cout << " 3. - Read matrix" << endl;
    cout << " 4. - Write matrix" << endl;
    cout << " 5. - Add matrices" << endl;
    cout << " 6. - Multiply matrices" << endl;
}

void Menu::get()
{
    int i,j;
    cout << "Give the index of the row: ";
    if(cin >> i)
    {

    }
    else
    {
        cout<<"Please Enter the valid index"<<endl;
        exit(0);
    }
    cout << "Give the index of the column: ";
    if(cin >> j)
    {

    }
    else
    {
        cout<<"Please Enter the valid index"<<endl;
        exit(0);
    }
    cout << "Give the index of the column: ";
    try
    {
        cout << "a[" << i << "," << j << "]= " << a.getElement(i,j)<< endl;
    }
    catch(cm1::Exceptions ex)
    {
        if(ex == cm1::OVERINDEXED)
            cout << "Invalid indexing!" << endl;
        else
            cout << "Unhandled ecxeption!" << endl;
    }
}

void Menu::set()
{
    int i,j,e;
    cout << "Give the index of the row: ";
    if(cin >> i)
    {

    }
    else
    {
        cout<<"Please Enter the valid index"<<endl;
        exit(0);
    }
    cout << "Give the index of the column: ";
    if(cin >> j)
    {

    }
    else
    {
        cout<<"Please Enter the valid index"<<endl;
        exit(0);
    }
    cout << "Give the index of the column: ";
    cout << "Give the value: ";
    cin >> e;
    try
    {
        a.setElement(i,j,e);
    }
    catch(cm1::Exceptions ex)
    {
        if(ex == cm1::OVERINDEXED)
        {
            cout << "Overindexing!" << endl;
        }
        else if(ex == cm1::INVALID)
        {
            cout << "This element should be Zero" << endl;
        }
        else
        {
            cout << "Unhandled Exception !" << endl;
        }
    }
}

void Menu::read()
{
        cout << "Give the size and the items of the matrix: ";
        try
        {
            cin >> a;
        }
         catch(cm1::Exceptions ex)
        {
           if(ex == cm1::INVALID)
            cout << "Matrix size not Defined" << endl;
        }
}

void Menu::write()
{
    cout << a << endl;
}

void Menu::sum()
{
    try
    {
        cm1 b;

        cout << "Give the size and the items of the second  matrix: " << endl;
        try
        {
        cin >> b;
        }
        catch(cm1::Exceptions ex)
        {
            if(ex == cm1::INVALID)
            cout << "Invalid Matrix Size!" << endl;
        }
        cout << "Sum of the matrices: " << endl;
        cout << a + b << endl;
    }
    catch(cm1::Exceptions ex)
    {
        if(ex == cm1::DIFFERENT)
            cout << "Different sizes!" << endl;
    }
}

void Menu::mul()
{
        cm1 b;

        cout << "Give the size and the items of the second  matrix: " << endl;
        try
        {
        cin >> b;
        }
         catch(cm1::Exceptions ex)
        {
            if(ex == cm1::INVALID)
            cout << "Invalid Matrix Size!" << endl;
        }
        try
        {
        cout << "Product of the matrices: " << endl;
        cout << a * b << endl;
        }
         catch(cm1::Exceptions ex)
        {
            if(ex == cm1::DIFFERENT)
            cout << "Different sizes!" << endl;
        }

}
