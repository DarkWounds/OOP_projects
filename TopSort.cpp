#include <bits/stdc++.h>
#define Marime 200003

using namespace std;

ifstream fin("topsort.in");
ofstream fout("topsort.out");

class Grafuri_Orientate
{
private:
    vector<int> a[Marime]; ///Matrice de adiacenta
    int * viz; ///Vector de vizitare
    int n, m;
    int len = 0, v[Marime]; ///Topologic
public:
    void SortTop(); ///Sortare topologica a nodurilor

    // Constructor si destructor pentru Grafuri_Orientate
    Grafuri_Orientate(int N, int M);
    ///~Grafuri_Orientate();

    // Metodele clasei Grafuri_Orientate
    int LungimeV();
    void Citire(const char* fisIn);
    int VTopologic(int i);
    void DFS(int k);
    int Size();
    Grafuri_Orientate& operator=(const Grafuri_Orientate& B);
};

    // Operatorul de atribuire pentru Grafuri_Orientate

    Grafuri_Orientate& Grafuri_Orientate::operator=(const Grafuri_Orientate& B)
    {
        n = B.n;
        m = B.m;
        for (int i = 1; i <= n; ++i)
            a[i] = B.a[i];
        return *this;
    }

    //Size
    int Grafuri_Orientate::Size()
    {
        return n;
    }

    // Constructor pentru Grafuri_Orientate
    Grafuri_Orientate::Grafuri_Orientate(int N, int M)
    {
        n = N;
        m = M;
        viz = new int[n + 1];
        for (int i = 0; i <= n; ++i)
            viz[i] = v[i] = 0;
    }

    // Returneaza lungimea vectorului de sortare topologica
    int Grafuri_Orientate::LungimeV()
    {
        return len;
    }

    // Citeste un graf orientat dintr-un fisier
    void Grafuri_Orientate::Citire(const char* fisIn)
    {
        ifstream fin_local(fisIn);
        int i, j;
        fin_local >> n >> m; // Citeste numarul de noduri si muchii
        // Realocam vectorii pentru noul n
        delete[] viz;
        viz = new int[n + 1];
        for (int i = 0; i <= n; ++i)
            viz[i] = v[i] = 0;
        for (int i = 0; i < Marime; ++i)
            a[i].clear();
        for(int p = 1; p <= m; p++)
        {
            fin_local >> i >> j;
            a[i].push_back(j);
        }
        fin_local.close();
    }

    //Returneaza nodul i in urma sortarii topologice
    int Grafuri_Orientate::VTopologic(int i)
    {
        return v[i];
    }

    //Parcurgere in adancime(Deep First Search)
    void Grafuri_Orientate::DFS(int k)
    {
        viz[k] = 1;
        for (int i : a[k])
            if (!viz[i])
                DFS(i);
        v[++len] = k;
    }

    // Sortare topologica a nodurilor
    void Grafuri_Orientate::SortTop()
    {
        len = 0;
        for(int i = 1; i <= n; i++)
            viz[i] = 0;
        for(int i = 1; i <= n; i++)
            if(!viz[i])
                DFS(i);
    }

int main()
{
    Grafuri_Orientate graf(0, 0);
    graf.Citire("topsort.in");
    graf.SortTop();
    for(int i = graf.Size(); i >= 1; i--)
        fout << graf.VTopologic(i) << " ";
    return 0;
}   