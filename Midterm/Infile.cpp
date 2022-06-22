#include "Infile.h"

Infile::Infile(const string &filename)
{
    f.open(filename);
    if(f.fail())
    {
        throw FILE_ERROR;
    }
}

Infile::~Infile()
{
    f.close();
}

void Infile::read()
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

void Infile::next()
{
  _end = (sx == abnorm);
  if(!_end)
  {
      curr.id = dx.ID;
      curr.cnt = 0;

      while((sx == Norm) && (curr.id == dx.ID))
      {
          curr.cnt++;
          read();
      }

  }
}
