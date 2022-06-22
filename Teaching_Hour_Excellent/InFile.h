#ifndef INFILE_H
#define INFILE_H

#include<bits/stdc++.h>
#include<fstream>

using namespace std;

struct Prof
{
    string sem;
    string neptun;
    int hour;

    friend istream &operator >> (istream &is, Prof &i)
   {
    is >> i.sem >> i.neptun >> i.hour ;
    return is;
   }
};

struct easy
{
    string date;
    int mhour;
};

enum Status {Norm,abnorm};

class InFile
{
    public:
        enum ERROR {FILE_ERROR};
        InFile(const string &filename);
        ~InFile();
         void first()
         {
              read();
              next();
         }
         void next();
         bool end()
         {
             return _end;
         }
         easy current()
         {
             return curr;
         }


    private:
        fstream f;
        Status sx;
        Prof dx;
        easy curr;
        bool _end;
        void read();
};

#endif // INFILE_H
