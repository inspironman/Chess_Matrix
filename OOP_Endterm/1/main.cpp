#include <iostream>
#include "../library/stringstreamenumerator.hpp"
#include "../library/seqinfileenumerator.hpp"
#include "../library/counting.hpp"
#include "../library/maxsearch.hpp"

using namespace std;

struct fish
{
    string name;
    int size;

    friend istream& operator>>(istream &is, fish &f)
    {
        is >> f.name >> f.size;
        return is;
    }
};

class FishCount : public Counting<fish> {};

struct contest
{
    string angler;
    string contest_name;
    int catches;

    friend istream& operator>>(istream &is , contest &c);

};

istream &operator>>(istream &is, contest &c)
{
    string line;
    getline(is,line,'\n');
    stringstream ss(line);
    ss >> c.angler >> c.contest_name;
    FishCount pr;
    StringStreamEnumerator<fish> ssenor(ss);
    pr.addEnumerator(&ssenor);
    pr.run();
    c.catches = pr.result();
    return is;
}

struct championship
{
    string name;
    int Cnt;
};

class AllFish : public Summation<contest,int>
{
private:
    string _name;
public:
    AllFish(const string &name) : _name(name) {}
protected:
    int func(const contest& e) const override {return e.catches;}
    int neutral() const override { return 0;}
    int add( const int& a, const int& b) const override { return a+b;}
    bool whileCond(const contest& e) const override { return e.contest_name == _name; }
    void first() override { }

};

class FishEnumerator : public Enumerator<championship>
{
private:
    SeqInFileEnumerator<contest>* _f;
    championship _champ;
    bool _end;
public:
    FishEnumerator(const string &fname) { _f = new SeqInFileEnumerator<contest>(fname);}
    ~FishEnumerator(){ delete _f;}
    void first() override { _f->first(); next();}
    void next() override;
    bool end() const override {return _end;}
    championship current() const override { return _champ;}
};
void FishEnumerator::next()
{
    if (_end = _f->end()) return;
    _champ.name = _f->current().contest_name;
    AllFish pr2(_champ.name);
    pr2.addEnumerator(_f);
    pr2.run();
    _champ.Cnt = pr2.result();
}

class MaxFish : public MaxSearch<championship,int>
{
protected:
    int func(const championship& e) const override { return e.Cnt;}
};

int main()
{
     try{

    MaxFish pr3;
    FishEnumerator fenor("input.txt");
    pr3.addEnumerator(&fenor);
    pr3.run();
    cout << "Maximum Fish has been caught at " << pr3.optElem().name <<" which is "<<pr3.opt()<<"\n";
    }catch (SeqInFileEnumerator<contest>::Exceptions e)
    {
        cout <<"File not found!\n";
    }
    return 0;
}
