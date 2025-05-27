#include <bits/stdc++.h>
#define Marime 1003

using namespace std;

ifstream fin("topsort.in");
ofstream fout("topsort.out");

class Grafuri_Orientate
{
private:
    vector<int> a[Marime]; ///Matrice de adiacenta
    int * viz; ///Vector de vizitare
    int n, m, * d; ///Numarul de noduri, numarul de muchii si vectorul de distante
    int * de, * di; ///Vectorul de grade de iesire (extern) si intrare (intern)
    int len = 0, v[Marime]; /// Lungimea vectorului de sortare topologica 
    /// si vectorul de noduri sortate
    void ReallocPointers(int n);
    void Clear(); 
    void Grade(); 
public:

     /// Constructor si destructor pentru Grafuri_Orientate
    Grafuri_Orientate(int N, int M);
    ~Grafuri_Orientate();

    /// Operatorul de atribuire pentru Grafuri_Orientate
    Grafuri_Orientate& operator=(const Grafuri_Orientate& B);

    /// Metodele clasei Grafuri_Orientate
    void Citire();
    void Citire(const char* fisIn);
    void Reset();
    int Size();
    void BFS(int k);
    void DFS(int k);
    int Distanta(int i);
    void SortTop(); 
    int VTopologic(int i);
    int Dextern(int i);
    int Dintern(int i);

};

    /// Constructor pentru Grafuri_Orientate
    Grafuri_Orientate::Grafuri_Orientate(int N, int M)
    {
        n = N;
        m = M;
        d = new int[n + 1];
        de = new int[n + 1];
        di = new int[n + 1];
        viz = new int[n + 1];
        for (int i = 0; i <= n; ++i)
            de[i] = di[i] = viz[i] = v[i] = 0;
    }

    /// Destructor pentru Grafuri_Orientate
   Grafuri_Orientate::~Grafuri_Orientate()
    {
        delete[] de;
        delete[] di;
        delete[] viz;
        delete[] d;
    }

    ///Operatorul de atribuire pentru Grafuri_Orientate
    Grafuri_Orientate& Grafuri_Orientate::operator=(const Grafuri_Orientate& B)
    {
        n = B.n;
        m = B.m;
        for (int i = 1; i <= n; ++i)
            a[i] = B.a[i];
        return *this;
    }

    /// Citeste un graf orientat de la tastatura
    void Grafuri_Orientate::Citire()
    {
        int i, j;
        cin >> n >> m; 
        ReallocPointers(n); 
        Clear();
        for(int p = 1; p <= m; p++)
        {
            cin >> i >> j;
            a[i].push_back(j);
        }
        Grade(); 
    }

    /// Citeste un graf orientat dintr-un fisier
    void Grafuri_Orientate::Citire(const char* fisIn)
    {
        ifstream fin_local(fisIn);
        int i, j;
        fin_local >> n >> m; 
        ReallocPointers(n);
        Clear(); 
        for(int p = 1; p <= m; p++)
        {
            fin_local >> i >> j;
            a[i].push_back(j);
        }
        Grade(); 
        fin_local.close();
    }

    /// Realoca pointerii pentru vectorii de grade, vizitare si distante
    void Grafuri_Orientate::ReallocPointers(int n)
    {
        delete[] de;
        delete[] di;
        delete[] viz;
        delete[] d;
        de = new int[n + 1];
        di = new int[n + 1];
        viz = new int[n + 1];
        d = new int[n + 1];
        for (int i = 0; i <= n; ++i)
            de[i] = di[i] = viz[i] = v[i] = 0;
    }

    /// Curata matricea de adiacenta si vectorii de vizitare
    /// si distante
    void Grafuri_Orientate::Clear()
    {
        for(int i = 1; i <= n; i++) 
        {
            a[i].clear();
            viz[i] = de[i] = di[i] = 0;
        }
    }

    /// Reseteaza vectorii de vizitare si distante
    void Grafuri_Orientate::Reset()
    {
        for(int i = 1; i <= n; i++)
            viz[i] = d[i] = 0;
    }

    /// Returneaza numarul de noduri din graf
    int Grafuri_Orientate::Size()
    {
        return n;
    }

    /// Parcurgere in latime (Breadth First Search)
    void Grafuri_Orientate::BFS(int k)
    {
        queue<int> q;
        for(int i = 1; i <= n; i++) 
        {
            viz[i] = 0;
            d[i] = 0;
        }
        q.push(k);
        d[k] = 0;
        viz[k] = 1;
        while(!q.empty())
        {
            int node = q.front(); q.pop();
            for (int i : a[node])
                if (!viz[i])
                {
                    viz[i] = 1;
                    q.push(i);
                    d[i] = d[node] + 1;
                }
        }
    }

    /// Parcurgere in adancime(Deep First Search)
    void Grafuri_Orientate::DFS(int k)
    {
        viz[k] = 1;
        for (int i : a[k])
            if (!viz[i])
                DFS(i);
        v[++len] = k;
    }

    /// Returneaza distanta de la nodul k la i
    int Grafuri_Orientate::Distanta(int i)
    {
        return d[i];
    }

    /// Sortare topologica a nodurilor
    void Grafuri_Orientate::SortTop()
    {
        len = 0;
        for(int i = 1; i <= n; i++)
            viz[i] = 0;
        for(int i = 1; i <= n; i++)
            if(!viz[i])
                DFS(i);
    }

    /// Returneaza nodul i in urma sortarii topologice
    int Grafuri_Orientate::VTopologic(int i)
    {
        return v[i];
    }

    /// Returneaza gradul de iesire al nodului i
    int Grafuri_Orientate::Dextern(int i)
    {
        return de[i];
    }

    /// Returneaza gradul de intrare al nodului i
    int Grafuri_Orientate::Dintern(int i)
    {
        return di[i];
    }

    /// Calculeaza gradele de intrare si iesire pentru fiecare nod
    void Grafuri_Orientate::Grade()
    {
        for (int i = 1; i <= n; i++)
         {
            for (int j : a[i]) {
                de[i]++;    
                di[j]++;  
            }
        }
    }

int main()
{
    Grafuri_Orientate graf(0, 0);
    
    ///Grade2--------------------------------

    /**graf.Citire();
    graf.Grade();
    int s = 0;
    for(int i = 1; i <= graf.Size(); i++)
        if(graf.Dintern(i) != 0 && graf.Dextern(i) == graf.Dintern(i)) s++;
    cout << s << "\n";
    for(int i = 1; i <= graf.Size(); i++)
        if(graf.Dextern(i) != 0 && graf.Dextern(i) == graf.Dintern(i))  cout << i << " ";
    cout << "\n";*/

    ///VarfuriPrietene--------------------------

    /**graf.Citire();
    int d1 = 0, d2= 0, cnt = 0;
    for(int i = 1; i <= graf.Size(); i++)
        for(int j = 1 + i; j <= graf.Size(); j++)
        {
            graf.BFS(i);
            d1 = graf.Distanta(j);
            graf.Reset();
            graf.BFS(j);
            d2 = graf.Distanta(i);
            if(d1 == d2 && d1 != 0)
            {
                cnt = 1;
                cout << i << " " << j << "\n";
            }
            graf.Reset();
        }
    if(cnt == 0)
        cout << "Nu exista" << "\n";*/

    /// TopSort --------------------Marime = 200003
    graf.Citire("topsort.in");
    graf.SortTop();
    for(int i = graf.Size(); i >= 1; i--)
        fout << graf.VTopologic(i) << " ";
    return 0;
}