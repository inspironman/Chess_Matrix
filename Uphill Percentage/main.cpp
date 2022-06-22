#include <iostream>
#include<fstream>

using namespace std;

int main()
{
    fstream f("input.txt");
    int first,second;

    int c = 0;
    int d = 0;

    f >> first;

    while(f >> second)
    {
        if(first < second) c++;
        d++;
        first = second;
    }

    double percent = (100.0 * c)/d;

    cout << percent << endl;
    return 0;
}
