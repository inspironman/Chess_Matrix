#include <iostream>
#include"Infile.h"

using namespace std;

int main()
{
    try
     {
         Infile t("input.txt");
         t.first();
         if(t.end())
         {
             cout<<"No Data in File";
         }
         else
         {
             string l = t.current().gteam;
             bool k = t.current().l;

             while(!t.end())
             {
                 if(k)
                 {
                      cout << l ;
                 }
                 t.next();
                 l = t.current().gteam;
             }
         }
     }
     catch (Infile::ERROR err)
     {
         cout << "Invalid File \n";
     }

}
