
///Lufthansa Group has published statistics about its flights in a sequential input file: date, plane ID, passenger capacity (PC), number of passengers (NoP).
///Which days had more, than 10 flights?

#include <iostream>
#include "InFile.h"

using namespace std;

int main()
{

    try
    {
        InFile t ("input.txt");
        int cnt = 0;
        t.first();
        if (t.end())
        {
            cout <<"Empty file!";
        }else
        {
            cout << "Days with more than 1 flights are: \n";
        while (!t.end() )
        {
            if (t.current().cnt > 1)
            {
                cnt++;
                cout << "\t"<< t.current().day << " "<< t.current().cnt <<endl;
            }
            t.next();
        }
        if (cnt == 0)
        {
                cout << "There was no day with more than 1 flights!\n";
        }
       }

    }
    catch(InFile ::ERROR err)
  {
    {
        cout << "Invalid File \n";
    }

  }

   return 0;
}
