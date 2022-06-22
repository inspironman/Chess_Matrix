#ifndef INFILE_H
#define INFILE_H

#include<bits/stdc++.h>
using namespace std;

struct race
{
    string tittle;
    string team;
    int hour;
    int min;
    int sec;

    friend istream &operator >> (istream &is, race &i)
    {
        is >> i.tittle >> i.team >> i.hour >> i.min >> i.sec;
        return is;
    }
};

struct lap
{
    string gteam;
    bool l = false;
};

enum Status {Norm,abnorm};

class Infile
{
    public:
        enum ERROR {FILE_ERROR};

        Infile(const string &filename);
        ~Infile();
        void read();
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
        lap current()
        {
            return curr;
        }


    private:
        fstream f;
        Status sx;
        race dx;
        lap curr;
        bool _end;

};

#endif // INFILE_H
