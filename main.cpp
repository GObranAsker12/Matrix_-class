#include <iostream>
using namespace std;

// template class Matrix
template <typename T>
class MATRIX
{
private:
  T** M; // matrix
  int m; // number of rows
  int n; // number of columns

public:
  // constructors
  MATRIX()
  {
    n = m = 0;

  }

  // constructor with two parameters
  MATRIX(int _m, int _n)
  {
    m = _m;
    n = _n;

    M = (T**) new T*[m]; // number of rows, the number of pointers

    // Allocate memory for each pointer
    for (int i = 0; i < m; i++)
      M[i] = (T*)new T[n];

    // fill array M with zeros
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        M[i][j] = 0;
  }

  // copy constructor - mandatory
  MATRIX(const MATRIX& _M)
  {

    m = _M.m;
    n = _M.n;

    // Allocate memory for M
    M = (T**) new T*[m]; // number rows, number pointers

    for (int i = 0; i < m; i++)
      M[i] = (T*) new T[n];

    // fill with values
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        M[i][j] = _M.M[i][j];
  }

  // access methods
  T GetMij(int i, int j)
  {
    if ((m > 0) && (n > 0))
      return M[i][j];
    else
      return 0;
  }
  bool addElementAt(int r, int c, int elem); //adds an element elem at the specified row r, and column c

  void SetMij(int i, int j, T value)
  {
    if ((i < 0) || (i >= m))
      return;
    if ((j < 0) || (j >= n))
      return;
    M[i][j] = value;
  }


  void displayMatrix(const char* ObjName)
  {
    cout << "Object: " << ObjName << endl;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
        cout << M[i][j] << "\t";
      cout << endl;
    }
    cout << "---------------------" << endl << endl;
  }

  // copy operator - mandatory
  MATRIX operator=(const MATRIX& _M)
  {
    if (n > 0)
    {
      // free memory previously allocated for the object *this
      for (int i = 0; i < m; i++)
        delete[] M[i];
    }

    if (m > 0)
    {
      delete[] M;
    }


    m = _M.m;
    n = _M.n;

    // Allocate memory for M again
    M = (T**) new T*[m];

    for (int i = 0; i < m; i++)
      M[i] = (T*) new T[n];


    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        M[i][j] = _M.M[i][j];
    return *this;
  }

  // Destructor - frees memory allocated for the matrix
  ~MATRIX()
  {
    if (n > 0)
    {
      // release the memory allocated for each row
      for (int i = 0; i < m; i++)
        delete[] M[i];
    }

    if (m > 0)
      delete[] M;
  }
};

int main()
{
  // test for class MATRIX
  MATRIX<int> M(2, 3);
  M.displayMatrix("M");

  // Fill the matrix with values according to the formula
  int i, j;
  for (i = 0; i < 2; i++)
    for (j = 0; j < 3; j++)
      M.SetMij(i, j, i + j);
  M.displayMatrix("M");

  MATRIX<int> M2 = M; // invoke the copy constructor
  M2.displayMatrix("M2");

  MATRIX<int> M3;
  M3 = M;
  M3.displayMatrix("M3");

}
