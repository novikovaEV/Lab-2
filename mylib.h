#if !defined MYHEDER_H
#define MYHEDER_H
class Matrix {
      int n,m;
 int **matr;
 public:
 Matrix();
 Matrix(int k,int r);
 Matrix(const Matrix&ob);
 void OutMatrix ();
 void OutMatrix (int s);
 Matrix OutMinor (int s);
 ~Matrix();
Matrix operator+(const Matrix &ob) const;
Matrix operator-(const Matrix &ob) const;
Matrix operator*(const Matrix &ob) const;
Matrix &operator=(const Matrix &ob);
 };
#endif
