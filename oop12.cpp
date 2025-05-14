#include <bits/stdc++.h>
#define nrprim 333367
using namespace std;

struct Pereche
{
    int val, fr;
};

class HashTable
{
protected:
    int P;
    vector<Pereche> h[nrprim];
public:
    HashTable()
    {
        P = nrprim;
    }
    /// adauga x in tabela de Hash
    void Add(int x)
    {
        int r = x % P;
        for (int i = 0; i < h[r].size(); i++)
            if (h[r][i].val == x)
            {
                (h[r][i].fr)++;
                return;
            }
        Pereche e = {x, 1};
        h[r].push_back(e);
    }
    /// ret. nr de ap ale lui x in hash
    int Search(int x)
    {
        int r = x % P;
        for (auto e : h[r])
            if (e.val == x) return e.fr;
        return 0;
    }

    /// sterge valoarea x din hash
    void Clear(int x)
    {
        int r = x % P;
        int len = h[r].size();
        for (int i = 0; i < len; i++)
            if (h[r][i].val == x)
            {
                h[r][i] = h[r][len - 1];
                h[r].pop_back();
                return;
            }
    }
    /// sterge o singura aparitie a lui x
    void Erase(int x)
    {
        int r = x % P;
        int len = h[r].size();
        for (int i = 0; i < len; i++)
            if (h[r][i].val == x)
            {
                if (h[r][i].fr > 0)
                    (h[r][i].fr)--;
            }
    }
/// sterge toate listele hash-ului
    void ClearAll()
    {
        for (int i = 0; i < P; i++)
            h[i].clear();
    }

int operator[](int x)
    {
        int r = x % P;
        for (auto e : h[r])
            if (e.val == x) return e.fr;
        return 0;
    }
};

class H2 : public HashTable
{
public:
    int SearchMinFr1()
    {
        int mn = 2000000001;
        for (int r = 0; r < P; r++)
        {
            for (auto e : h[r])
                if (e.fr == 1 && mn > e.val)
                    mn = e.val;
        }
        return mn;
    }
};

int main()
{
    int i, n, x;
    H2 w;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> x;
        w.Add(x);
    }
    /// caut in hash cea mai mica valoare care apare o singura data
    cout << w.SearchMinFr1();
    /**
    Test ClearAll
    HashTable a;
    a.Add(23); a.Add(23); a.Add(35);
    a.Add(23); a.Add(3); a.Add(35);
    cout << a[23] << " " << a[35] << " " << a[100] << "\n";
    */
    return 0;
}
