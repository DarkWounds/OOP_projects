#include <bits/stdc++.h>
#define nrprim 333367
using namespace std;

/**
7 4
1 2 3 3 3 3 4

     1 2 3 4 5 6 7 8
fr = 1 1 2 0 0 0 0 0

cnt = 2
total = 2+1+0+1
*/

int a[123459], n, k;

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
};

class SumUnice : public HashTable
{
public:
    int Calcul()
    {
        int i, nr, cnt = 0;
        long long total;
        /// prelucram primele k numere din vectorul a
        for (i = 1; i <= k; i++)
        {
            Add(a[i]);
            nr = Search(a[i]);
            if (nr == 1) cnt++;
            else if (nr == 2) cnt--;
        }
        total = cnt;
        /// prelucram restul secventelor de lungime k:
        for (i = k + 1; i <= n; i++)
        {
            /// secventa curenta de lungime k este a[i-k+1..i]
            /// deci a[i] intra in secv, iar a[i-k] iese
            Add(a[i]);
            nr = Search(a[i]);
            if (nr == 1) cnt++;
            else if (nr == 2) cnt--;

            Erase(a[i - k]);
            nr = Search(a[i - k]);
            if (nr == 1) cnt++;
            else if (nr == 0) cnt--;

            total += cnt;
        }
        return total;
    }
};

void Citire()
{
    int i;
    cin >> n >> k;
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += 1000000000;
    }
}

int main()
{
    SumUnice w;
    Citire();
    cout << w.Calcul();
    return 0;
}
