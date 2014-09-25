#include "mylib.h"
#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <stdio.h>

using namespace std;

Matrix::~Matrix()          
          {
           for (int i=0;i<n;i++)
		   delete[] matr[i];
           delete[]matr;
           }

Matrix::Matrix()
{
 srand ( time(NULL) );
 n=rand()%10;
 m=rand()%10;
 matr=new int*[n];
 for (int i=0;i<n;i++) {
  matr[i] = new int [m];
}
srand ( time(NULL) );
 for(int i=0;i<n;i++) {
       for(int j=0;j<m;j++)
     matr[i][j]=rand()%10;
     }
}

Matrix::Matrix(int k,int r)
{   n=k;
 m=r;
 matr=new int*[n];
 for (int i=0;i<n;i++) {
  matr[i] = new int [m];
}
srand ( time(NULL) );
 for(int i=0;i<n;i++) {
       for(int j=0;j<m;j++)
     {
     matr[i][j]=rand()%10;
     }
     }
}

Matrix::Matrix(const Matrix&ob)
{n=ob.n;
 m=ob.m;
  matr=new int*[n];
 for (int i=0;i<n;i++) {
  matr[i] = new int [m];
}
  for(int i=0;i<n;i++) {
     for(int j=0;j<m;j++)
     matr[i][j]=ob.matr[i][j];
     }
}

void Matrix::OutMatrix()
{

     for (int i=0; i<n; i++)
{
for (int j=0; j<m; j++)
cout<<matr[i][j]<<"\t";
cout<<endl;
}
 }
 
 void Matrix::OutMatrix(int s)
{

     for (int i=0; i<s; i++)
{
for (int j=0; j<s; j++)
cout<<matr[i][j]<<"\t";
cout<<endl;
}
 }

Matrix Matrix::OutMinor(int s)
{
     int a,b;
     Matrix arr(s,s);
     if (s>n&&s>m||s==0)
          cout<<"Error";
          srand ( time(NULL) );
          if (n==s) a=0;
          else a=rand()%(n-s);
          if (m==s) b=0;
          else b=rand()%(m-s);
               for (int i=a; i<a+s; i++)
{
for (int j=b; j<b+s; j++)
arr.matr[i-a][j-b]=matr[i][j];
}
return arr;
}

Matrix Matrix::operator+(const Matrix &ob) const
{
        Matrix temp(* this);
        for (int i=0; i<ob.n; i++)
        {
           for (int j=0; j<ob.m; j++)
           temp.matr[i][j]=matr[i][j]+ob.matr[i][j];
           }
           return temp;
};

Matrix Matrix::operator-(const Matrix &ob) const
{
        Matrix temp(*this);
        for (int i=0; i<ob.n; i++)
        {
           for (int j=0; j<ob.m; j++)
           temp.matr[i][j]=matr[i][j]-ob.matr[i][j];
           }
           return temp;
};

Matrix Matrix::operator*(const Matrix &ob) const
{
        Matrix temp(* this);
        for (int i=0;i<ob.n;i++)
        {
           for (int j=0;j<ob.n;j++)
           {
               int scal=0;
               for (int k=0;k<ob.n;k++)
               scal+=matr[i][k]*ob.matr[k][j];
               temp.matr[i][j]=scal;
               }
           }
           return temp;
};

Matrix &Matrix::operator=(const Matrix &ob)
{
        if (&ob == this) 
        return *this;
		if (matr)
		{
			for (int i=0;i<ob.n;i++)
			{
				delete[] matr[i];
			}
			delete[] matr;
		}
		 matr=new int*[ob.n];
 for (int i=0;i<ob.n;i++) {
  matr[i] = new int [ob.m];
}
		n = ob.n;
		m = ob.m;
		for (int i=0; i<n; i++)
        {
           for (int j=0; j<m; j++)
           matr[i][j]=ob.matr[i][j];
           }
           return *this;
};
