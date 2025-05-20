#include <bits/stdc++.h>
using namespace std;

ifstream fin("paranteze.in");
ofstream fout("paranteze.out");

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

/// punem pe stiva 0 si 1, unde 0 este '(' iar 1 este ')'
class Paranteze : public Backtracking
{
public:
    Paranteze(int _n, int _vmin, int _vmax)
    : Backtracking(_n, _vmin, _vmax) {}

    virtual bool Valid(int top, int x)
    {
        int nrd = 0, nri = 0;
        if (x == 0) nrd++;
        else nri++;
        for (int i = 1; i < top; i++)
            if (st[i] == 0) nrd++;
            else nri++;
        if (nrd < nri) return false;
        if (nrd > n / 2) return false;
        return true;
    }

    virtual void Afis(int len)
    {
        for (int i = 1; i <= len; i++)
            fout << (char)(st[i] + '(');
        fout << "\n";
    }
};

/**
Avem o clasa A in care exista metoda F(), iar in clasa derivata
B avem definita iar functia F().
Daca F() nu este virtuala, atunci la un apel de forma
ob.F(), unde ob este de tip B, atunci este posibil sa se
apeleze F() din clasa de baza A, nu din B, cum vrem noi.
*/

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
    /// gen permutari ale lui {1,2,...,n}
    int n;
    cin >> n;
    GenPerm p(n, 1, n);
    p.Back(1);
    /// generare aranjamente
    int n, k;
    fin >> n >> k;
    GenPerm a(k, 1, n);
    a.Back(1);
    */
    int n;
    fin >> n;
    Paranteze e(n, 0, 1);
    e.Back(1);
    return 0;
}
