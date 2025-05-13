#include <bits/stdc++.h>
using namespace std;

class Matrice
{
private:
    int a[101][101];
    int n;

public:
    Matrice(int sz)
    {
        n = sz;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                a[i][j] = 0;
    }

    Matrice(int sz, int val)
    {
        n = sz;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                a[i][j] = val;
    }

    Matrice(const char fisIn[])
    {
        ifstream fin(fisIn);
        fin >> n;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                fin >> a[i][j];
        fin.close();
    }

    Matrice& operator=(const Matrice& A)
    {
        n = A.n;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                    a[i][j] = A.a[i][j];
        return *this;
    }

    Matrice operator*(const Matrice& B)
    {
        /// C = A * B
        /// c[i][j] = a[i][1]*b[1][j] + ... + a[i][n] * b[n][j]
        Matrice C(n);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                C.a[i][j] = 0;
                for (int k = 1; k <= n; k++)
                    C.a[i][j] += a[i][j] * B.a[i][j];
            }
        return C;
    }

    Matrice operator+(const Matrice& A)
    {
        Matrice B(n);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                B.a[i][j] = a[i][j] + A.a[i][j];
        return B;
    }

    void SetV(int i, int j, int val)
    {
        a[i][j] = val;
    }

    int Size()
    {
        return n;
    }

    friend ostream& operator<<(ostream &out, Matrice &A)
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
};

int main()
{
    Matrice m1(6), m2("mat.in");
    m1 = m2;
    cout << m1;
    Matrice m3 = m1 + m2;
    cout << m3;
    Matrice m4 = m1 * m3;
    cout << m4;
    return 0;
}
