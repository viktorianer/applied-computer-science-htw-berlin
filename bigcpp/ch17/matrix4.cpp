#include <iomanip>
#include <sstream>

#include "matrix4.h"

string MatrixIndexException::format_message(int n)
{
   ostringstream outstr;
   outstr << "Matrix index " << n << " out of range";
   return outstr.str();
}

Matrix::Matrix(int r, int c)
   : rows(r), columns(c), elements(new double[rows * columns])
{
   for (int i = 0; i < rows * columns; i++)
      elements[i] = 0;
}
   
Matrix& Matrix::operator=(const Matrix& other) 
{
   if (this != &other)
   {
      free();
      copy(other);
   }
   return *this;
}

void Matrix::copy(const Matrix& other)
{
   rows = other.rows;
   columns = other.columns;
   elements = new double[rows * columns];
   for (int i = 0; i < rows * columns; i++)
      elements[i] = other.elements[i];
}

double& Matrix::operator()(int i, int j) throw (MatrixIndexException)
{
   if (i < 0 || i >= rows)
      throw MatrixIndexException(i);
   if (j < 0 || j >= columns)
      throw MatrixIndexException(j);
   return elements[i * get_columns() + j];
}

double Matrix::operator()(int i, int j) const throw (MatrixIndexException)
{
   if (i < 0 || i >= rows)
      throw MatrixIndexException(i);
   if (j < 0 || j >= columns)
      throw MatrixIndexException(j);
   return elements[i * get_columns() + j];
}
   
Matrix& Matrix::operator+=(const Matrix& right) 
   throw (MatrixMismatchException)
{
   if (rows != right.rows || columns != right.columns)
      throw MatrixMismatchException();
   for (int i = 0; i < rows; i++)
      for (int j = 0; j < columns; j++)
         (*this)(i, j) += right(i, j);
   return *this;
}

Matrix operator+(const Matrix& left, const Matrix& right) 
   throw (MatrixMismatchException)
{
   Matrix result = left;
   result += right;
   return result;
}
   
Matrix operator*(const Matrix& left, const Matrix& right) 
   throw (MatrixMismatchException)
{
   if (left.get_columns() != right.get_rows())
      throw MatrixMismatchException();
   Matrix result(left.get_rows(), right.get_columns());
   for (int i = 0; i < left.get_rows(); i++)
      for (int j = 0; j < right.get_columns(); j++)
         for (int k = 0; k < left.get_columns(); k++)         
            result(i, j) += left(i, k) * right(k, j); 
   return result;
}
   
Matrix operator*(const Matrix& left, double right)
{
   Matrix result(left);
   for (int i = 0; i < result.get_rows(); i++)
      for (int j = 0; j < result.get_columns(); j++)
         result(i, j) *= right; 
   return result;
}
   
ostream& operator<<(ostream& left, const Matrix& right)
{
   const int WIDTH = 10;
   for (int i = 0; i < right.get_rows(); i++)
   {
      for (int j = 0; j < right.get_columns(); j++)
         left << setw(WIDTH) << right(i, j);
      left << "\n";
   }
   return left;
}

