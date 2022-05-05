#include"InFile.h"

istream &operator >> (istream &is, Measurement &m)
{
    is >> m.Date >> m.distance >> m.weight ;
    return is;
}

istream &operator >> (istream &is, BlackHole &s)
{
    string line;
    getline(is,line,'\n');

    stringstream ss(line);

    ss >> s.ID;
    s.close = false;
    s.lastweight = 0;

    Measurement m;

    while (ss >> m)
    {
        s.close = s.close || (m.distance < 2700);
        s.lastweight = m.weight;
    }
    return is;
}

InFile::InFile(const string &filename)
{
    file.open(filename.c_str());
    if (file.fail())
    {
        throw FILE_ERROR;
    }


}

void InFile::read()
{
     if (file >> dx)
     {
         sx = Norm;
     }
     else
     {
         sx = abmorm;
     }


}
