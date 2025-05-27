#include <bits/stdc++.h>
#define Marime 103

using namespace std;

ifstream fin("topsort.in");
ofstream fout("topsort.out");

class Grafuri_Orientate
{
private:
    vector<int> a[Marime]; ///Matrice de adiacenta
    int * viz; ///Vector de vizitare
    int n, m, * d; ///Numarul de noduri, numarul de muchii si vectorul de distante
    int * de, * di; ///Grad extern si intern
    int nrctc = 1; /// Nr componente conexe
    int len = 0, v[Marime]; ///Topologic
    void Grade(); /// Calculeaza gradele de intrare si iesire pentru fiecare nod
public:
    void SortTop(); ///Sortare topologica a nodurilor

    // Constructor si destructor pentru Grafuri_Orientate
    Grafuri_Orientate(int N, int M);
    ~Grafuri_Orientate();

    // Metodele clasei Grafuri_Orientate
    int LungimeV();
    void Citire(const char* fisIn);
    int VTopologic(int i);
    int Dextern(int i);
    int Dintern(int i);
    int Distanta(int i);
    void incrementareNrctc();
    int Viz(int i);
    int Nrctc();
    void Citire();
    int Size();
    void Clear();
    void Reset();
    void BFS(int k);
    void DFS(int k);
    void VizAfis();
    int Vizitate();
    Grafuri_Orientate& operator=(const Grafuri_Orientate& B);
};

    //Operatorul de atribuire pentru Grafuri_Orientate

    Grafuri_Orientate& Grafuri_Orientate::operator=(const Grafuri_Orientate& B)
    {
        n = B.n;
        m = B.m;
        for (int i = 1; i <= n; ++i)
            a[i] = B.a[i];
        delete[] viz;
        delete[] d;
        viz = new int[n + 1];
        d = new int[n + 1];
        for (int i = 0; i <= n; ++i)
            viz[i] = d[i] = 0;
        return *this;
    }

    // Destructor pentru Grafuri_Orientate
    Grafuri_Orientate::~Grafuri_Orientate()
    {
        delete[] viz;
        delete[] d;
        delete[] de;
        delete[] di;
    }

    // Constructor pentru Grafuri_Orientate
    Grafuri_Orientate::Grafuri_Orientate(int N, int M)
    {
        n = N;
        m = M;
        d = new int[n + 1];
        de = new int[n + 1];
        di = new int[n + 1];
        viz = new int[n + 1];
        for (int i = 0; i <= n; ++i)
            de[i] = di[i] = viz[i] = d[i] = 0;
    }

    // Calculeaza gradele de intrare si iesire pentru fiecare nod
    void Grafuri_Orientate::Grade()
    {
        for (int i = 1; i <= n; i++) {
            de[i] = 0;
            di[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            for (int j : a[i]) {
                de[i]++;   // grad extern (out-degree)
                di[j]++;   // grad intern (in-degree)
            }
        }
    }

    // Citeste un graf orientat dintr-un fisier
    void Grafuri_Orientate::Citire(const char* fisIn)
    {
        ifstream fin_local(fisIn);
        int i, j;
        int N, M;
        fin_local >> N >> M;
        Grafuri_Orientate A(N, M);
        for (int p = 1; p <= M; ++p) {
            fin_local >> i >> j;
            A.a[i].push_back(j);
        }
        *this = A; // foloseste operatorul =
    }

    // Returneaza lungimea vectorului de sortare topologica
    int Grafuri_Orientate::LungimeV()
    {
        return len;
    }

    // Returneaza nodul de pe pozitia i din vectorul de sortare topologica
    int Grafuri_Orientate::VTopologic(int i)
    {
        return v[i];
    }

    //Returneaza gradul de iesire al nodului i
    int Grafuri_Orientate::Dextern(int i)
    {
        return de[i];
    }
    //Returneaza gradul de intrare al nodului i
    int Grafuri_Orientate::Dintern(int i)
    {
        return di[i];
    }
    //Returneaza numarul de componente conexe
    int Grafuri_Orientate::Nrctc()
    {
        return nrctc;
    }

    //Incrementeaza numarul de componente conexe
    void Grafuri_Orientate::incrementareNrctc()
    {
        nrctc++;
    }

    //Parcurgere in adancime (Depth First Search)
    void Grafuri_Orientate::DFS(int k)
    {
        viz[k] = 1;
        v[++len] = k; // adauga nodul la vectorul de sortare topologica
        for (int i : a[k])
            if (!viz[i])
                DFS(i);
    }


    //Returneaza distanta de la nodul k la i
    int Grafuri_Orientate::Distanta(int i)
    {
        return d[i];
    }


    //Returneaza 1 daca nodul i a fost vizitat, altfel 0
    int Grafuri_Orientate::Viz(int i)
    {
        return viz[i];
    }

    //Returneaza numarul de noduri din graf
    int Grafuri_Orientate::Size()
    {
        return n;
    }

    //Curata matricea de adiacenta si vectorii de vizitare
    // si distante
    void Grafuri_Orientate::Clear()
    {
        for(int i = 1; i <= n; i++)
        {
            a[i].clear();
            viz[i] = 0;
        }
    }

    //Reseteaza vectorii de vizitare si distante
    void Grafuri_Orientate::Reset()
    {
        for(int i = 1; i <= n; i++)
            viz[i] = d[i] = 0;
    }

    //Parcurgere in latime (Breadth First Search)
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

    //Afiseaza nodurile vizitate
    // in urma unei parcurgeri
    void Grafuri_Orientate::VizAfis()
    {
        for(int i = 1; i <= n; i++)
            if(Viz(i))
                cout << i << " ";
        cout << "\n";
    }

    // Verifica daca toate nodurile au fost vizitate
    int Grafuri_Orientate::Vizitate()
    {
        for(int i = 1; i <= n; i++)
            if(Viz(i) == 0) return 0;
        return 1;
    }

    // Citeste un graf orientat de la tastatura
    // si calculeaza gradele de intrare si iesire
    void Grafuri_Orientate::Citire()
    {
        int i, j;
        int N, M;
        cin >> N >> M;
        Grafuri_Orientate A(N, M);
        for (int p = 1; p <= M; ++p) {
            cin >> i >> j;
            A.a[i].push_back(j);
        }
        *this = A; // foloseste operatorul =

    }


int main()
{
    Grafuri_Orientate graf(1,1);
    graf.Citire();
    int d1 = 0, d2 = 0, cnt = 0;
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
        cout << "Nu exista" << "\n";

    return 0;
}