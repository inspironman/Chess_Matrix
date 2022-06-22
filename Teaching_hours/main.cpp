#include <iostream>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

struct Prof
{
    string sem;
    string neptun;
    int hours;

//    friend istream &operator >>(istream &is, Prof &i)
//    {
//        string line;
//        getline(is , line ,'\n');
//        stringstream ss(line);
//        ss>>i.sem>>i.neptun>>i.hours;
//        return is;
//    }

    friend istream &operator>>(istream &is, Prof &a)
    {

        is >> a.sem >> a.neptun >> a.hours ;

        return is;
    }
};

enum Status {norm,abnorm};

void read(Status &sx, Prof &e , fstream &f)
{
    f >> e;
    if(f.fail())
    {
        sx = abnorm;
    }
    else
    {
        sx = norm;
    }
}

int lesshour(Status &sx,Prof &e, fstream &f)
{
    read(sx,e,f);
    int cnt = 0;

    while(sx == norm && !(e.neptun == "gfhdjs" && e.hours > 15))
    {
        read(sx,e,f);
    }
    read(sx,e,f);
    while(sx == norm)
    {
        if(e.neptun == "gfhdjs" && e.hours < 15)
        {
            cnt ++ ;
        }
        read(sx,e,f);
    }
    return cnt;
}

int main()
{

    fstream f("input.txt");
    Prof a;
    Status sx = norm;
    if(f.fail())
    {
        cout<<"File Opening Failed"<<endl;
    }
    else
    {
        int result = lesshour(sx,a,f);
        cout << result;
    }
     return 1;
}
