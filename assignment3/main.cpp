#include<iostream>
#include<bits/stdc++.h>
#include<exception>
#include "../library/summation.hpp"
#include "../library/procedure.hpp"
#include "../library/maxsearch.hpp"
#include "../library/seqinfileenumerator.hpp"
#include "../library/stringstreamenumerator.hpp"
#include "../library/counting.hpp"
#include "../library/linsearch.hpp"

using namespace std;

struct Fish
{
    string name;
    int size;
    friend istream &operator>>(istream &is, Fish &f)
    {
        is >> f.name >> f.size;
        return is;
    }
};

class FishCount : public Counting<Fish> {};

struct Contest
{
    string angler;
    string ID;
    int catches;
    friend istream &operator>>(istream &is,Contest &C);
};

class line : public LinSearch<Contest>
{
     bool cond(const Contest& e) const override {return e.catches == 0;}
};

istream &operator>>(istream &is,Contest &C)
{
    string line;
    getline(is,line,'\n');
    stringstream ss(line);
    ss >> C.angler >> C.ID;
    FishCount pr;
    StringStreamEnumerator<Fish> ssenor(ss);
    pr.addEnumerator(&ssenor);
    pr.run();
    C.catches = pr.result();
    return is;
}

struct Champ
{
    string name;
    int Cnt;
};

class AllFish : public Summation<Contest,int>
{
private:
    string _name;
public:
    AllFish(const string &name) : _name(name) {}
protected:
    int func(const Contest& e) const override {return e.catches;}
    int neutral() const override { return 0;}
    int add( const int& a, const int& b) const override { return a+b;}
    bool whileCond(const Contest& e) const override { return e.ID == _name; }
    void first() override { }

};

class FishEnumerator : public Enumerator<Champ>
{
private:
    SeqInFileEnumerator<Contest>* _f;
    Champ _champ;
    bool _end;
public:
    FishEnumerator(const string &fname) { _f = new SeqInFileEnumerator<Contest>(fname);}
    ~FishEnumerator(){ delete _f;}
    void first() override { _f->first(); next();}
    void next() override;
    bool end() const override {return _end;}
    Champ current() const override { return _champ;}
};
void FishEnumerator::next()
{
    if (_end = _f->end()) return;
    _champ.name = _f->current().ID;
    AllFish pr2(_champ.name);
    pr2.addEnumerator(_f);
    pr2.run();
    _champ.Cnt = pr2.result();
}

class MaxFish : public MaxSearch<Champ,int>
{
protected:
    int func(const Champ& e) const override { return e.Cnt;}
};

int main()
{
    try{

    MaxFish pr3;
    line pr4;
    string filename ;
    cout << "Enter the File name \n";
    cin >> filename;
    system("CLS");
    FishEnumerator fenor(filename);
    SeqInFileEnumerator<Contest> enor(filename);
    pr4.addEnumerator(&enor);
    pr3.addEnumerator(&fenor);
    pr3.run();
    pr4.run();

    if (pr4.found())
    {
        cout <<"First angler with the contest ID, with at least one contest without catch is " <<pr4.elem().angler << " "<< pr4.elem().ID << endl << endl ;
    }
    else
    {
        cout << "Not Found " <<endl ;
    }
    cout << "#####################################################################"<<endl<<endl;
    cout << "Maximum Fish has been caught at " << pr3.optElem().name <<" which is "<<pr3.optElem().Cnt<<"\n"<<endl;

    }catch (SeqInFileEnumerator<Contest>::Exceptions e)
    {
        cout <<"File not found!\n";
    }
    return 0;
}
