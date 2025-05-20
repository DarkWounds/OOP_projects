#include <bits/stdc++.h>
using namespace std;

ifstream fin("combinari.in");
ofstream fout("combinari.out");

class Backtracking
{
protected:
    int st[30]; /// stiva
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

class Combinari : public Backtracking
{
public:
    Combinari(int _n, int _vmin, int _vmax)
    : Backtracking(_n, _vmin, _vmax)
    {
        st[0] = 0;
    }

    virtual void Back(int top)
    {
        if (top == n + 1) Afis(n);
        else for (int i = st[top - 1] + 1; i <= vmax; i++)
        {
            st[top] = i;
            Back(top + 1);
        }
    }
};


int main()
{
    int n, k;
    fin >> n >> k;
    Combinari comb(k, 1, n);
    comb.Back(1);
    return 0;
}
