#include<iostream>
#include<bits/stdc++.h>
#include"../library/summation.hpp"
#include"../library/stringstreamenumerator.hpp"
#include"../library/seqinfileenumerator.hpp"
#include"../library/procedure.hpp"
#include"../library/maxsearch.hpp"

using namespace std;

struct Result
{
    int sum;
    int count;
    Result () {} ;
    Result (int s,int cnt) : sum(s), count(cnt) {};
};


class Average : public Summation<int , Result>
{
     Result func(const int& e) const override {return Result (e,1);}
     Result neutral() const override {return Result(0,0);}
     Result add( const Result& a, const  Result& b) const override {return Result(a.sum + b.sum , a.count + b.count);}
     bool  cond(const int& e) const override { return true; }
};

struct Student
{
    string name;
    double gpa;

    friend istream& operator >>(istream &is, Student &s);
};

istream& operator >>(istream &is, Student &s)
{
    string line;
    getline (is,line, '\n');

    stringstream ss(line);
    ss >> s.name;

    Average f;

    StringStreamEnumerator<int> enor(ss);
    f.addEnumerator(&enor);

    f.run();

    if (f.result().count != 0)
    {
        s.gpa = double (f.result().sum) / f.result().count;
    }
    else
    {
        s.gpa = 0;
    }
    return is;
}

class best : public MaxSearch <Student , double , Less<double>>
{
      double func(const Student& e) const override {return e.gpa;}
      bool  cond(const Student& e) const override { return true;}
};

int main()
{
    best stu;
    SeqInFileEnumerator<Student> enor("input.txt");

    stu.addEnumerator(&enor);
    stu.run();

    cout << stu.optElem().name << " " << stu.optElem().gpa ;
}
