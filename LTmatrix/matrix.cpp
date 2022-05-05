#include "matrix.h"


matrix::matrix()
{
    _size = 3;
    _vec = [1,2,3,4,5,6];
}

matrix::matrix(int size)
{
    _size = size;
    _vec.resize(size*(size+1)/2,0);
}
 matrix::matrix(const string &filename)
 {
     fstream f(filename);
     if(f.fail())
     {
         cout<<"File Reading Failed"<<endl;
         _size = 0;
         _vec.clear();
     }
     else
     {
         int e;
         while(f >> e)
         {
             _vec.push_back(e);
         }
         double n = calculatesize(_vec.size);

     if (n == flatten(n))
     {
         _size = n;
     }
     else
     {
         _size = 0;
         _vec.clear();
     }

     }

     // PRIVATE METHODS

     int matrix::ind (int i,int j) const
     {
         return ((i*(i-1)/2) + j);
     }

     double matrix::calculatesize (unsigned int size)
     {
         return (sqrt(8.0*size + 1)-1)/2.0;
     }

     bool matrix::checklower (int i,int j)
    {
        return (1 <= j && j <= i && i <= _size);
    }

    int matrix::getElement(int i,int j) const
    {
        if(checklower)
        {
            return _vec[ind(i,j)];
        }
        else if ( 1 <= j && j <= _size && 1 <= i && i <= _size)
        {
            return 0;
        }
        else
        {
            throw Invalid_index() ;
        }
    }

    void matrix::setVec(const vector<int>&vec)
    {
        double n = calculatesize (vec.size());
        if(n == floor(n))
        {
            _size = n;
            _vec = vec;
        }
        else
        {
            throw Invalid_Vector_size() ;
        }
    }

    void matrix::setElement(int a,int b,int c)
    {
        if (checklower (a,b))
        {
            _vec[ind(a,b)] = c;
        }
        else
        {
            throw Out_of_LTmatrix() ;
        }
    }

    matrix::matrix add(const matrix &a, const matrix &b)
    {
       if(a.getSize() == b.getSize())
       {
           matrix sum(a.getSize());

           for(int i = 0; i < b.getSize ; i++)
           {
               sum._vec[i] = a._vec[i] + b._vec[i];
           }
           return sum;
       }
       else
       {
           throw Different_size_matrix() ;
       }
    }

    matrix::matrix mult(const matrix &a, const matrix &b)
    {
        if(a.getSize() == b.getSize())
        {
            for(int i = 0; i <= a._size;i++)
            {
                for(int j = 0; j <= a._size; j++)
                {
                    for(int k = j ; j <= i ; k++)
                    {
                        mult.setElement(i,j,mult.getElement(i,j) + a.getElement(i,k)*b.getElement(k,i));
                    }
                }
            }
            return mult;
        }
        else
        {
            throw Different_size_matrix() ;
        }
    }

     friend ostream& operator<<(ostream &os, const matrix &a)
     {
         os << m._size() <<"x" << m._size()<<endl;
         for(int i = 0; i <= m._size();i++)
         {
             for(int j = 0; j <= m._size(); j++)
             {
                 os << m.getElement(i,j)<<" ";
             }
             os<<endl;
         }
         return os;
     }

 }
