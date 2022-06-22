#include "Infile.h"


ostream &operator <<(ostream &os, const Occurence &o)
{
    os << "Number " << o.num << "  Occurence "<<o.cnt <<endl ;
}

Infile::Infile(const string &filename)
{
    file.open(filename.c_str());
    if (file.fail())
    {
        throw FILE_ERROR;
    }

}

Infile::~Infile()
{
    file.close();
}

void Infile :: read()
{
    file >> dx;
    if (file.fail())
    {
        sx = abnorm;
    }
    sx = norm;
}

void Infile ::next()
{
    if (!(abnorm == sx))
    {
        curr.num = dx;
        curr.cnt = 0;

        for ( ; curr.num == dx ; read())
        {
            curr.cnt++;
        }

    }

}
