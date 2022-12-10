#pragma once
#include<bits/stdc++.h>
using namespace std;

class cm1
{
public:
    enum Exceptions{OVERINDEXED,DIFFERENT,INVALID};

//CONSTRUCTORS

    cm1()
    {
        _vec.clear();
    }
    cm1(int k);
    cm1(const vector<int> &v);
    cm1(const cm1& a);

//METHODS

    int msize() const;
    int getElement(int i, int j) const;
    void setElement(int a, int b,int c);
    friend ostream& operator<<(ostream &os, const cm1 &a);
    friend istream& operator>> (istream& s, cm1& a);
    friend cm1 operator+ (const cm1& a, const cm1& b);
    friend cm1 operator* (const cm1& a, const cm1& b);

private:
    vector<int> _vec;
     int getSize() const
    {
        return _vec.size();
    }
    int ind(int i,int j,int size) const;
    bool inOrder(int i,int j) const;
};
