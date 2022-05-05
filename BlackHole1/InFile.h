#pragma once
#include<bits/stdc++.h>
#include<fstream>

using namespace std;

struct BlackHole
{
    string ID;
    int lastweight;
    bool close;

    friend istream &operator >> (const istream &is, BlackHole &s);
};

struct Measurement
{
    string Date;
    int distance;
    int weight;

    friend istream &operator >> (istream &is, Measurement &m);
};

enum Status {abmorm,Norm};

class InFile
{
private:
  ifstream file;
  BlackHole dx;
  Status sx;
  void read();
  bool _end;

public:

    enum ERROR {FILE_ERROR};

    InFile(const string &filename);
    ~InFile()
    {
        file.close();
    }
    void first()
    {
        read();
    }
    void next()
    {
        read();
    }
    bool end()
    {
        return sx == abmorm;
    }
    BlackHole current()
    {
        return dx;
    }
};

