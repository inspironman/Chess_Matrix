#ifndef MATRIX_H
#define MATRIX_H
#include<vector>
#include<fstream>
#include<math.h>
#include<iostream>

using namespace std;

class matrix
{
    public:

       class Invalid_index : public exception {};
       class Out_of_Triangle : public exception {} ;
       class Different_size_matrix : public exception {};

        matrix();
        matrix(int a);
        matrix (const string &filename);

      void getSize() const
      {
        return _size;
      }

      int getElement(int i, int j) const;

      friend ostream& operator<<(ostream &os, const matrix &a);

      void setVec(const vector<int>&vec);

      void setElement (int a, int b, int c);

      static matrix add(const matrix &a, const matrix &b);
      static matrix mult(const matrix &a, const matrix &b);


    private:
        int _size;
        vector<int>_vec;

        int ind(int i,int j) const;
        double calculatesize (unsigned int size);
        bool checklower (int i,int j);
        int getElement(int i,int j) const;

};

#endif // MATRIX_H
