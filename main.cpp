#include <iostream.h>
#include "mylib.h"

using namespace std;

int main()
{
    int a,b;
    cout<<"Vvedite razmernosti matricy:"<<endl;
    cin>>a>>b;
    
    Matrix M(a,b);
    M.OutMatrix();
    cout<<endl;

    int d;
    cout<<"Vvedite razmernost' minora:"<<endl;
    cin>>d;
   
  cout<<"Minor1:"<<endl;
  Matrix N;
 N=M.OutMinor(d);
 N.OutMatrix(d);
    cout<<endl;
    
      cout<<"Minor2:"<<endl;
  Matrix P;
 P=M.OutMinor(d);
 P.OutMatrix(d);
    cout<<endl;
    M.~Matrix();
    
   cout<<"Symma minorov:"<<endl; 
   Matrix C;
   C=N+P;
  C.OutMatrix(d);
    cout<<endl;
    
    cout<<"Raznost' minorov:"<<endl; 
    Matrix D;
    D=N-P;
  D.OutMatrix(d);
    cout<<endl;
    
    cout<<"Proizvedenie minorov:"<<endl; 
   Matrix E;
   E=N*P;
   E.OutMatrix(d);
   
   N.~Matrix();
   P.~Matrix();
   C.~Matrix();
   D.~Matrix();
   E.~Matrix();

    getch();
     return 0;
}
