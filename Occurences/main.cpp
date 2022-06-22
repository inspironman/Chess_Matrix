/*
Calculating the occurences of the numbers in a Sequential Input File that is sorted in ascending order.
File is enumerated by using a Custom Enumerator.
*/

#include<bits/stdc++.h>
#include"Infile.h"
using namespace std;

int main()
{
  string filename ;
  cout<<"Enter the FileName \n";
  cin>>filename;

  try
  {
      Infile t (filename);

      for (t.first(); t.end(); t.next())
      {
          cout << t.current();
      }

  }
  catch(Infile::Errors e)
  {
      cout<<"File Opening Unsuccsessful ";
  }

   return 0;
}
