#pragma once
#include<iostream>
#include<fstream>

using namespace std;

struct Occurence
{
    int num;
    int cnt;

    friend ostream &operator << (ostream&os, const Occurence &o);
};

enum Status {abnorm,norm};

class Infile
{
private:

   ifstream file;
   Status sx;
   int dx;
   Occurence curr;
   bool _end = (sx == abnorm);
   void read();

public:

    enum Errors {FILE_ERROR};

    Infile(const string &filename);
    ~Infile();
    Occurence current()
    {
        return curr;
    }

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

};



