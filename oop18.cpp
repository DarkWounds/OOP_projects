#include <bits/stdc++.h>
using namespace std;

ifstream fin("descp2.in");
ofstream fout("descp2.out");

class Backtracking
{
protected:
    int st[130]; /// stiva
    int n; /// lungimea solutiei
    int vmin, vmax; /// valorile max si min de pe un nivel din st
public:
    Backtracking(int _n, int _vmin, int _vmax)
    {
        n = _n; vmin = _vmin; vmax = _vmax;
    }
    int operator[](int i)
    {
        return st[i];
    }
    virtual void Afis(int len)
    {
        for (int i = 1; i <= len; i++)
            fout << st[i] << " ";
        fout << "\n";
    }

    int Size()
    {
        return n;
    }

    friend ostream& operator<<(ostream &out, Backtracking &A)
    {
        for (int i = 1; i <= A.Size(); i++)
            out << A[i] << " ";
        out << "\n";
        return out;
    }

    virtual bool Valid(int top, int x)
    {
        return true;
    }

    virtual void Back(int top)
    {
        if (top == n + 1) Afis(n);
        else for (int i = vmin; i <= vmax; i++)
            if (Valid(top, i))
            {
                st[top] = i;
                Back(top + 1);
            }
    }
};

class Puteri2 : public Backtracking
{
protected:
    int a[8];
    int S;
public:
    Puteri2(int _n, int _vmin, int _vmax, int suma)
    : Backtracking(_n, _vmin, _vmax)
    {
        st[0] = 1;
        S = suma;
        a[1] = 2;
        for (int i = 2; i <= 7; i++)
            a[i] = a[i - 1] * 2;
    }

    virtual void Afis(int len)
    {
        for (int i = 1; i <= len; i++)
            fout << a[st[i]] << " ";
        fout << "\n";
    }

    virtual void Back(int top, int suma)
    {
        if (suma == S) Afis(top - 1);
        else for (int i = st[top - 1]; i <= vmax; i++)
            if (suma + a[i] <= S)
            {
                st[top] = i;
                Back(top + 1, suma + a[i]);
            }
    }
};


int main()
{
    int suma;
    fin >> suma;
    Puteri2 w(0, 1, 7, suma);
    w.Back(1, 0);
    return 0;
}
