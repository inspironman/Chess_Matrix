#include "cm1.h"
cm1::cm1(int k)
{
       _vec.clear();
       _vec.resize(k,0);
}
cm1::cm1(const vector<int> &v)
{
    _vec = v;
}
cm1::cm1(const cm1 &a)
{
    int s = a.getSize();
    _vec.resize(s);
    for (int i = 0; i < s; i++)
    {
        _vec[i] = a._vec[i];
    }
}
                                         // PRIVATE METHODS
//================================================================================================================================================================

int cm1::ind(int i,int j,int size) const
{
    if(size%2 == 0)
    {
     int n = ((i-1)*size/2) + ((j+1)/2);
     return n;
    }
    else
    {
     int n = ((i-1)*size/2) + ((j+2)/2);
     return n;
    }
}

bool cm1::inOrder(int i,int j) const
{
    if ((i%2 == 0 && j%2 == 0) || (i%2 == 1 && j%2 == 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
                                                 // PUBLIC METHODS
//===========================================================================================================================================================
//Task: 	Get the Size of Matrix
//Input:    Matrix having non-zero element in vector
//Output:   Matrix Size
//Activity: Returning square root of (vector size * 2)

int cm1::msize() const
{
        return sqrt((_vec.size())*2);
}

//Task: 	Get the  Element of Matrix of given Index
//Input:    Row Number and Column Number
//Output:   Element at the Given index
//Activity: Returning element of Given index by using a private Method.

int cm1::getElement(int i, int j) const
{
    int size = msize();
    if((i <= size && j <= size) && (i > 0 && j > 0))
    {
    if (inOrder(i,j))
    {
        return _vec[(ind(i,j,size))-1];
    }
    else
    {
        return 0;
    }
    }
    else
    {
        throw OVERINDEXED;
    }

}

//Task: 	Set the  Element of Matrix of given Index
//Input:    Row Number and Column Number
//Output:   Nothing
//Activity: Setting element of Given index by using two private Method.

void cm1::setElement(int a,int b,int c)
{
    int size = msize();
    if((a <= size && b <= size ) && (a > 0 && b > 0))
    {
         if (inOrder(a,b))
        {
            _vec[ind(a,b,size)-1] = c;
        }
        else if(!inOrder(a,b) && c == 0 )
        {

        }
        else
        {
            throw INVALID;
        }
    }
    else
    {
        throw OVERINDEXED;
    }

}

//Task: 	Reading
//Input:    istream is - source of writing
//          cm1 a     - matrix
//Output:   istream is - source of writing
//Activity: reads the elements of the all valid index of the matrix

istream& operator>> (istream& is, cm1& a)
{
   a._vec.clear();
   int size;
   is>>size;
   if(size <= 0) throw cm1::INVALID;

   a._vec.resize(0);
   int n = size;
   for (int i = 1; i <= n; i++)
   {
       for (int j = 1; j <= n; j++)
       {
           if((i%2 == 0 && j%2 == 0) || (i%2 == 1 && j%2 == 1))
           {
               int c = 0;
               cout<<"["<<i<<","<<j<<"]"<<" ";
               is>>c;
               a._vec.push_back(c);
           }

       }

   }

   return is;

}

//Task: 	writing
//Input:    ostream os - target of writing
//          cm1 a     - matrix
//Output:   ostream os - target of writing
//Activity: writes the elements of the matrix at Valid index

ostream& operator<<(ostream &os, const cm1 &a)
{
    int n = sqrt((a._vec.size())*2);
         os <<n<<"x" <<n<<endl;
         for(int i = 1; i <= n;i++)
         {
             for(int j = 1; j <= n; j++)
             {
                 os <<setw(5)<<a.getElement(i,j);
             }
             os<<endl;
         }

         return os;
}

//Task: 	adding
//Input:    cm1 a    - matrix
//          cm1 b    - matrix
//Output:   cm1 c    - result matrix
//Activity: adds the elements of the matrices

cm1 operator+(const cm1& a ,const cm1& b)
{
    int s = a.getSize();
    if(s != b.getSize()) throw cm1::DIFFERENT;

    cm1 c(s);

    for(int i = 0; i < s; ++i)  c._vec[i] = a._vec[i] + b._vec[i];
    return c;
}

//Task: 	adding
//Input:    cm1 a    - matrix
//          cm1 b    - matrix
//Output:   cm1 c    - result matrix
//Activity: Multiply the elements of the matrices

cm1 operator*(const cm1& a ,const cm1& b)
{
    int s = a.getSize();
    if(s != b.getSize())
    {
        throw cm1::DIFFERENT;
    }
    else
    {
    int n = sqrt((a._vec.size())*2);
    cm1 m(s);
    for(int i = 1; i <= n; i++)
    {
       for (int j = 1; j <= n; j++)
       {
           int c = 0;
           for (int k = 1; k <= n; k++)
           {
               c = c + a.getElement(i,k)*b.getElement(k,j);
                m.setElement(i,j,c);
           }
       }
    }
    return m;
    }
}

