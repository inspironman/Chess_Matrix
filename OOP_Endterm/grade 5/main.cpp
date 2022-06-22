#include <iostream>
#include "../library/stringstreamenumerator.hpp"
#include "../library/seqinfileenumerator.hpp"
#include "../library/summation.hpp"
#include "../library/linsearch.hpp"
#include "../library/enumerator.hpp"


using namespace std;
struct Data
{
    int round;
    string name;
    int score;
};
istream &operator>> (istream &is,Data &c)
    {
        is >> c.round >> c.name >> c.score;
        return is;
    }

struct Player
{
    int round;
    string name;
    int score;

    Player()
    {
        score=0;
    }

    Player(const int &n,const string &nam,const int&y):round(n),name(nam),score(y) { }
};

class Result : public Summation<Data,Player>
{
public:
    Result(const int &roun,const string &nam) : _round(roun),_name(nam) { }
private:
    int _round;
    string _name;


    Player func(const Data& e) const  override
    {
        return Player(e.round,e.name,e.score);
    }
    Player neutral() const override { return Player(); }
    Player add(const Player& a, const Player& b) const  override
    {
        return Player(a.round,a.name,a.score+b.score);
    }

    void first() override { }
    bool whileCond(const Data& current) const override
    {
        return (current.round == _round && current.name == _name);
    }
};

class PlayerEnumerator : public Enumerator<Player>
{
private:
    SeqInFileEnumerator<Data>* _f;
    Player _current;
    bool _end;
public:
    PlayerEnumerator(const string &fname){ _f = new SeqInFileEnumerator<Data>(fname); }
    ~PlayerEnumerator() { delete _f; }
    void first() override { _f->first(); next();}
    void next() override;
    Player current() const override { return _current; }
    bool end() const override { return _end; }
};

void PlayerEnumerator::next()
{
    if (_end = _f->end()) return;


    _current.round = _f->current().round;
    _current.name=_f->current().name;
    Result pr(_current.round,_current.name);
    pr.addEnumerator(_f);
    pr.run();
    _current = pr.result();
}

class optLinear : public LinSearch<Player,true>
{
    protected:
    bool cond(const Player& e) const override
    {
        return e.score>=10;
    }
};

int main()
{
    try
    {
        PlayerEnumerator enor("input6.txt");
        optLinear pr;
        pr.addEnumerator(&enor);
        pr.run();
        if (pr.found())
        {
            cout << "Yes" <<endl;
        }
        else
        {
            cout << "No" <<endl;
        }


    }
    catch (SeqInFileEnumerator<Data>::Exceptions err)
    {
        cout<<"File not found!\n";
        return 1;
    }
    return 0;
}
