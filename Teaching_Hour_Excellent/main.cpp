#include <iostream>
#include<fstream>
#include "InFile.h"

using namespace std;

int main()
{
     try
     {
         InFile t("input.txt");
         t.first();
         if(t.end())
         {
             cout<<"No Data in File";
         }
         else
         {
             int min = t.current().mhour;
             string l = t.current().date;

             while(!t.end())
             {
                 if(t.current().mhour < min)
                 {
                     min = t.current().mhour;
                     l = t.current().date;
                 }
                 t.next();
             }
             cout << l << " " << min;
         }
     }
     catch (InFile::ERROR err)
     {
         cout << "Invalid File \n";
     }

     return 0;
}
