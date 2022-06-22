#ifndef INFILE_H
#define INFILE_H

#include<bits/stdc++.h>
using namespace std;

struct worker
{
    string ID;
    int hours;

     friend istream &operator >> (istream &is, worker &i)
    {
        is >> i.ID >> i.hours;
        return is;
    }
};

struct need
{
    string id;
    int cnt;
};

enum Status {Norm,abnorm};

class Infile
{
    public:
        enum ERROR {FILE_ERROR};
        Infile(const string &filename);
        ~Infile();
        void next();
        void first()
        {
            read();
            next();
        }
        bool end()
        {
            return _end;
        }
        need current()
        {
            return curr;
        }


    private:
         void read();
         fstream f;
         need curr;
         worker dx;
         Status sx;
         bool _end;

};

#endif // INFILE_H
