#include <bits/stdc++.h>
using namespace std;
ifstream in("permutari.in");
ofstream out("permutari.out");

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
            out << st[i] << " ";
        out << "\n";
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

class GenPerm : public Backtracking
{
public:
    GenPerm(int _n, int _vmin, int _vmax)
    : Backtracking(_n, _vmin, _vmax) {}

    virtual bool Valid(int top, int x)
    {
        for (int i = 1; i < top; i++)
            if (st[i] == x) return false;
        return true;
    }
};

int main()
{
    /**
    /// generearea sirurilor de 4 biti
    Backtracking b(4,0,1);
    b.Back(1);
    cout << "\n\n";
    /// generarea produsului cartezian {1,2,3}x{1,2,3}x{1,2,3}
    Backtracking c(3,1,3);
    c.Back(1);
    */
    int n;
    in >> n;
    GenPerm p(n, 1, n);
    p.Back(1);
    return 0;
}
