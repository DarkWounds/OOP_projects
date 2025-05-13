#include <bits/stdc++.h>
#define nrprim 333367
using namespace std;

/**
Hash Table
---------

P = 7
L[0]: MMM 28
L[1]: BBB 57, DDD 99
L[2]: FFF 44
L[3]: GGG 31, KKK 38, LLL 59
L[4]: CCC 11, EEE 25, HHH 67, NNN 46
L[5]: III 19
L[6]: AAA 34, JJJ 83
                                  i
h[r] : (a, 3) (b, 5), (d, 17), (g,1), (e, 6), (f, 9)
*/

struct Pereche
{
    int val, fr;
};

class HashTable
{
private:
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
    HashTable w;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> x;
        w.Add(x);
    }
    /// caut in hash cea mai mica valoare care apare o singura data
    cout << w.SearchMinFr1();
    return 0;
}
