#include<iostream>
#include "matrix.h"

using namespace std;

int main()
{
    matrix a;

    try
    {
        cout<<a.getElement(2,3)<<endl;
    }
    catch (matrix::Invalid_index ex)
    {
        cout<<"Invalid"<<endl;
    }

    return 0;
}
