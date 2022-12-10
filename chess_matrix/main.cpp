#include<bits/stdc++.h>
#include "menu.h"
#include "cm1.h"
using namespace std;

//#define NORMAL_MODE
#ifndef NORMAL_MODE

int main()
{
       //cm1 a,b;
      //cin >> a;
     //cin >> b;
    //cm1 c = a*b;
   //cout << c;
      Menu m;
      m.run();
    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
TEST_CASE("create", "inp.txt")
{
    const string fileName = "inp.txt";

    ifstream in(fileName.c_str());
    if(in.fail())
    {
        cout << "File name error!" << endl;
        exit(1);
    }

    cm1 c;
    in >> c; // 3
    CHECK (c.getElement(1,1) == 1);
    CHECK (c.getElement(1,2) == 0);
    CHECK (c.getElement(2,1) == 0);
    CHECK (c.getElement(3,2) == 0);
    CHECK (c.getElement(2,2) == 3);
    CHECK (c.getElement(3,3) == 5);

    cm1 b;
    in >> b; // 2
    CHECK (c.getElement(1,1) == 1);
    CHECK (c.getElement(2,1) == 0);

    cm1 a;
    in >> a; // 1
    CHECK (c.getElement(1,1) == 1);
}

TEST_CASE("getting and changing an element of the matrix", "")
{
    vector<int>v;
    v = {5,6,9,5,6};
    vector<int>u;
    u = {9,3,6,5,53};
    cm1 b(u);
    cm1 a(v);
    CHECK (a.getElement(1,1) == 5);
    a.setElement(1,1,12);
    CHECK (a.getElement(1,1) == 12);

    CHECK (b.getElement(3,3) == 53);
    b.setElement(3,3,7);
    CHECK (b.getElement(3,3) == 7);

    cm1 c = a + b;
    CHECK (c.getElement(3,3) == 13);

}

TEST_CASE("add", "inp2.txt")
{
    const string fileName = "inp2.txt";

    ifstream in(fileName.c_str());
    if(in.fail())
    {
        cout << "File name error!" << endl;
        exit(1);
    }

    cm1 a, b, e, z; // 3
    in >> a >> b >> z >> e;

    cm1 c = a + b;
    CHECK (c.getElement(1,1)  == 6);
    CHECK (c.getElement(2,1) == 0);
    CHECK (c.getElement(2,2) == 6);
    CHECK (c.getElement(3,2) == 0);

    cm1 d = b + a;
    CHECK (c.getElement(1,1) == d.getElement(1,1));
    CHECK (c.getElement(2,2) == d.getElement(2,2));
    CHECK (c.getElement(3,3) == d.getElement(3,3));

    cm1 g = (a + b) + c;
    cm1 f = a + (b + c);
    CHECK (g.getElement(1,1) == f.getElement(1,1));
    CHECK (g.getElement(1,2) == f.getElement(1,2));
    CHECK (g.getElement(3,1) == f.getElement(3,1));

    cm1 h = a + z; // Checking for the zero elements
    CHECK (h.getElement(1,2) == z.getElement(1,2));
    CHECK (h.getElement(2,1) == z.getElement(2,1));
    CHECK (h.getElement(3,2) == z.getElement(3,2));

     // Checking for the non-zero elements
    CHECK (h.getElement(1,1) > z.getElement(1,1));
    CHECK (h.getElement(2,2) > z.getElement(2,2));
    CHECK (h.getElement(3,3) > z.getElement(3,3));
    CHECK (h.getElement(1,3) > z.getElement(1,3));

}

TEST_CASE("multi", "inp2.txt")
{
    const string fileName = "inp2.txt";

    ifstream in(fileName.c_str());
    if(in.fail())
    {
        cout << "File name error!" << endl;
        exit(1);
    }

    cm1 a, b, e, z; // 3
    in >> a >> b >> z >> e;

    cm1 c = a * b;
    CHECK (c.getElement(1,1) == 9);
    CHECK (c.getElement(1,2) == 0);
    CHECK (c.getElement(2,3) == 0);
    CHECK (c.getElement(2,1) == 0);
    CHECK (c.getElement(2,2) == 9);
    CHECK (c.getElement(3,1) == 30);
    CHECK (c.getElement(3,3) == 21);

    cm1 d = b * a;
    CHECK (c.getElement(1,1) != d.getElement(1,1));
    CHECK (c.getElement(3,3) != d.getElement(3,3));

    cm1 g = (a * b) * c;
    cm1 f = a * (b * c);
    CHECK (g.getElement(1,1) == f.getElement(1,1));
    CHECK (g.getElement(1,2) == f.getElement(1,2));
    CHECK (g.getElement(3,1) == f.getElement(3,1));

    cm1 h = a * z;
    CHECK (h.getElement(1,2) == z.getElement(1,2));
    CHECK (h.getElement(2,1) == z.getElement(2,1));
    CHECK (h.getElement(3,2) == z.getElement(3,2));

    CHECK (h.getElement(1,1) > z.getElement(1,1));
    CHECK (h.getElement(2,2) > z.getElement(2,2));
    CHECK (h.getElement(3,3) > z.getElement(3,3));
    CHECK (h.getElement(1,3) > z.getElement(1,3));

}

TEST_CASE("exceptions", " ")
{

    cm1 b(3);

    try
    {
        b.getElement(3,5);
    }
    catch(cm1::Exceptions ex)
    {
        CHECK(ex == cm1::OVERINDEXED);
    }

    cm1 d(2);
    cm1 e(3);
    try
    {
       cm1 f = d + e;
    }
    catch(cm1::Exceptions ex)
    {
        CHECK(ex == cm1::DIFFERENT);
    }

    cm1 g(5);
    cm1 h(7);
    try
    {
        cm1 j = g + h;
    }
    catch(cm1::Exceptions ex)
    {
        CHECK(ex == cm1::DIFFERENT);
    }


    cm1 p(5);
    try
    {
       p.setElement(1,2,5);
    }
    catch(cm1::Exceptions ex)
    {
        CHECK(ex == cm1::INVALID);
    }

}

TEST_CASE("Extreme_Size", "inp3.txt")
{
    const string fileName = "inp3.txt";

    ifstream in(fileName.c_str());
    if(in.fail())
    {
        cout << "File name error!" << endl;
        exit(1);
    }

    cm1 c;
    in >> c; // 3
    CHECK (c.getElement(1,1) == 200);
    CHECK (c.getElement(1,2) == 0);
    CHECK (c.getElement(1,3) == 199);
    CHECK (c.getElement(3,2) == 0);
    CHECK (c.getElement(2,2) == 190);
    CHECK (c.getElement(20,20) == 1);

}

#endif


