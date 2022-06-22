#include <iostream>
#include "../library/stringstreamenumerator.hpp"
#include "../library/seqinfileenumerator.hpp"
#include "../library/linsearch.hpp"
#include "../library/counting.hpp"
#include "../library/summation.hpp"

using namespace std;

struct Data
{
    int round;
    string name;
    int score;
    bool isG;
};
istream &operator>> (istream &is,Data &c)
    {
        is >> c.round >> c.name >> c.score;
        c.isG = (c.score == 10);
        return is;
    }

class MyCount : public Counting<Data>
{
    bool cond(const Data & e) const override{
        return (e.isG);
    }
};

int main()
{
    try
    {
        SeqInFileEnumerator<Data> enor("input.txt");
        MyCount pr;
        pr.addEnumerator(&enor);
        pr.run();
            cout << pr.result() <<endl;
    }
    catch (SeqInFileEnumerator<Data>::Exceptions err)
    {
        cout<<"File not found!\n";
        return 1;
    }
    return 0;
}
