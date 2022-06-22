#ifndef INFILE_H
#define INFILE_H

#include<bits/stdc++.h>
#include<fstream>
using namespace std;

struct flight
{
    string date;
    string id;
    int PC;
    int NoP;

    friend istream &operator >> (istream &is, flight &i)
    {
    is >> i.date >> i.id >> i.PC >> i.NoP;
    return is;
    }
};

struct need
{
    string day;
    int cnt;
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

        need current() const
        {
            return curr;
        }
        bool end()
        {
            return _end;
        }


    private:
        fstream f;
        Status sx;
        flight dx;
        need curr;
        void read();
        bool _end;

};

#endif // INFILE_H
