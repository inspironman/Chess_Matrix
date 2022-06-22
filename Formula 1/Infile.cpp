#include "Infile.h"

Infile::Infile(const string &filename)
{
    f.open(filename);
    if (f.fail())
    {
        throw FILE_ERROR;
    }
}

Infile::~Infile()
{
    f.close();
}

void Infile :: read()
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

void Infile :: next()
{
    _end = (sx == abnorm);

    if(!(_end))
    {
        curr.gteam = dx.team;

        while ((sx == Norm) && (curr.gteam == dx.team))
        {
            if(((dx.hour < 1) || (dx.hour <= 1 && dx.min < 17)) )
            {
                 curr.l = true;
            }
            read();
        }
    }
}
