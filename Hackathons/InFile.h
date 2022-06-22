#ifndef INFILE_H
#define INFILE_H

#include<bits/stdc++.h>
#include<fstream>
#include<vector>
#include<sstream>

using namespace std;

struct hackacthon
{
    string id;
    string name;
    vector<int>score;

    friend istream &operator >>(istream &is, hackacthon &i)
    {
        string line;
        getline(is,line,'\n');

        stringstream ss(line);

        ss >> i.id >> i.name;
        int e;

        while(ss >> e)
        {
            score.push_back(e);
        }

        return is;
    }




};


class InFile
{
    public:
        InFile();
       ~InFile();

    protected:

    private:
};

#endif // INFILE_H
