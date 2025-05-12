#include <bits/stdc++.h>
using namespace std;

/// clasa matricelor patratice
class Matrix
{
private:
    int a[102][102];
    int n;
public:
    Matrix(int dim, int val)
    {
        n = dim;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                a[i][j] = val;
    }
    Matrix(const char fisIn[])
    {
        ifstream fin(fisIn);
        fin >> n;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                fin >> a[i][j];
        fin.close();
    }
    Matrix(int dim)
    {
        n = dim;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                a[i][j] = rand() % 100;
    }
    Matrix(Matrix &A)
    {
        n = A.n;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                a[i][j] = A.a[i][j];
    }
    int Size()
    {
        return n;
    }
    friend ostream& operator<<(ostream &out, Matrix &A)
    {
        for (int i = 1; i <= A.Size(); i++)
        {
            for (int j = 1; j <= A.Size(); j++)
                out << A.a[i][j] << " ";
            out << "\n";
        }
        out << "\n";
        return out;
    }

    Matrix operator=(const Matrix& other)
    {
        n = other.n;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                a[i][j] = other.a[i][j];
        return *this;
    }

    Matrix& operator+(Matrix& other)
    {
        Matrix rezultat(n, 0);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                rezultat.a[i][j] = a[i][j] + other.a[i][j];

        return rezultat;
    }
    /**
    Matrix operator +(const Matrix &A)
    {
        Matrix C(n, 0);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                C.a[i][j] = A.a[i][j] + a[i][j];
        return C;
    }

    Matrix& operator=(Matrix &A)
    {
        n = A.n;
        for (int i = 1; i <= A.Size(); i++)
            for (int j = 1; j <= A.Size(); j++)
                a[i][j] = A.a[i][j];
        return *this;
    }
    */
};

int main()
{
    srand(time(0));
    Matrix A(6);
    cout << A;
    Matrix B(6);
    cout << B;
    Matrix C(A.Size(), 0);
    C = A + B;
    cout << C;
    return 0;
}
