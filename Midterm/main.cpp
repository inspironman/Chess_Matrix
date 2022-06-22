#include <iostream>
#include "Infile.h"

using namespace std;

int main()
{

    try
    {
        Infile t ("input.txt");
        t.first();

        string l = t.current().id;
        int c = t.current().cnt;

        if (t.end())
        {
            cout <<"Empty file!";
        }else
        {
            cout << "Worker with more working days are : ";
        while (!t.end() )
        {
            if (c < t.current().cnt )
            {
                 l = t.current().id;
                 c = t.current().cnt;
            }
            t.next();
        }

        cout << l << endl;

        }

    }
    catch(Infile ::ERROR err)
  {
    {
        cout << "Invalid File \n";
    }

  }

   return 0;
}
