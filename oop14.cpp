#include <bits/stdc++.h>
#define nrprim 33367
using namespace std;

ifstream fin("complementar.in");
ofstream fout("complementar.out");

/**
5 6
101001 - 41
010110 - 22
010110 - 22
111111 - 63
000000 - 0
101001 - 41
010110 - 22
010110 - 22
101001 - 41
010110 - 22
010110 - 22

41, 22, 22, 63, 0, 41, 22, 22, 41, 22, 22
Cate perechi (a[i], a[j]) au a[i]^a[j] = 63

cnt = 0+1+1+0+1+2+
*/

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

    int operator[](int x)
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
};

int main()
{
    HashTable a;
    int i, j, x, n, m, W; /// W = 2^m - 1
    char s[33];
    long long cnt = 0;
    fin >> n >> m;
    W = (1 << m) - 1;
    for (i = 1; i <= n; i++)
    {
        fin >> s;
        x = 0;
        for (j = 0; s[j] != 0; j++)
            x = x * 2 + (s[j] - '0');
        cnt += a[x ^ W];
        a.Add(x);
    }
    fout << cnt << "\n";
    return 0;
}
