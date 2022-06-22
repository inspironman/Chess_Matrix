#include "InFile.h"



InFile::InFile(const string &filename)
{
    f.open(filename);

    if(f.fail())
    {
        throw FILE_ERROR;
    }
}

InFile::~InFile()
{
    f.close();
}

void InFile::read()
{
    f >> dx;
    if(f.fail())
    {
        sx = abnorm;
    }
    else
    {
        sx = Norm;
    }
}

void InFile::next()
{
    _end = (sx == abnorm);

    if(!(_end))
    {
        curr.mhour =  0;
        curr.date = dx.sem;

        while ((sx == Norm) && (curr.date == dx.sem))
        {
            curr.mhour += dx.hour;
            read();
        }
    }
}
