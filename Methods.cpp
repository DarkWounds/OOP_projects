#include "Grafuri_Orientate.cpp"

using namespace std;

  int Grafuri_Orientate::Size()
    {
        return n;
    }

    void Grafuri_Orientate::Clear()
    {
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                a[i][j].muchie = a[i][j].cost = d[j] = viz[j] = 0;
    }

    void Grafuri_Orientate::Reset()
    {
        for(int i = 1; i <= n; i++)
            viz[i] = d[i] = 0;
    }

    void Grafuri_Orientate::BFS(int k)
    {
        int q[103], ul, pr;
        pr = ul = 1; q[ul] = k;
        d[k] = 0; viz[k] = 1;
        while(pr <= ul)
        {
            k = q[pr++];
            for(int i = 1; i <= n; i++)
                if(a[k][i].muchie && !viz[i])
                {
                    viz[i] = 1;
                    q[++ul] = i;
                    d[i] = d[k] + 1;
                }
        }
    }

    void Grafuri_Orientate::DFS(int k)
    {
        viz[k] = 1;
        for (int i = 1; i <= n; i++)
            if (!viz[i] && a[k][i].muchie)
                DFS(i);
        v[++len] = k;
    }

    void Grafuri_Orientate::DFS1(int k)
    {
        viz[k] = nrctc;
        for (int i = 1; i <= n; i++)
            if (!viz[i] && a[k][i].muchie)
                DFS1(i);
    }

    void Grafuri_Orientate::Verificare()
    {
        for(int i = 1; i <= n; i++)
            if(viz[i])
                cout << i << " ";
        cout << "\n";
    }

    int Grafuri_Orientate::Vizitate()
    {
        for(int i = 1; i <= n; i++)
            if(viz[i] == 0) return 0;
        return 1;
    }

    void Grafuri_Orientate::AfisMatriceFaraCost()
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
                cout << a[i][j].muchie << " ";
            cout << "\n";
        }
    }

    void Grafuri_Orientate::AfisMatriceCost()
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
                cout << a[i][j].cost << " ";
            cout << "\n";
        }
    }

    void Grafuri_Orientate::SortTop()
    {
        for(int i = 1; i <= n; i++)
            if(!viz[i])
                DFS(i);
    }

    void Grafuri_Orientate::AfisTopologic()
    {
        for(int i = n; i >= 1; i--)
            cout << v[i] << " ";
        cout << "\n";
    }

    void Grafuri_Orientate::AfisParcurgeri()
    {
        int viz = 0;
        for(int i = 1; i <= n; i++)
        {
            DFS(i);
            if(Vizitate())
            {
                cout << i << " ";
                viz = 1;
            }
            Reset();
        }
        if(viz == 0) cout << "Nu sunt noduri ce pot vizita toate celelalte nodurui";
        cout << "\n";
    }

    void Grafuri_Orientate::AfisGrade()
    {
        Grade();
        cout << "Grade externe ";
        for(int i = 1; i <= n; i++)
            cout << de[i] << " ";
        cout << "\n" << "Grade interne ";
        for(int i = 1; i <= n; i++)
            cout << di[i] << " ";
        cout << "\n";
    }

    void Grafuri_Orientate::MersCircuite(int i, int j)
    {
    for(int k = 1; k <= n; k++)
        if(a[j][k].muchie == 1 && a[k][i].muchie == 1)
            cout << i << " " << j << " " << k << "\n";
    }

    void Grafuri_Orientate::AfisCircuite()
    {
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(a[i][j].muchie)
                    MersCircuite(i, j);
    }

    void Grafuri_Orientate::MersCicluri(int i, int j)
    {
        for(int k = 1; k <= n; k++)
            if((a[i][k].muchie == 1 || a[k][i].muchie == 1) && (a[k][j].muchie == 1 || a[j][k].muchie == 1))
                cout << i << " " << j << " " << k << "\n";
    }

    void Grafuri_Orientate::AfisCicluri()
    {
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(a[i][j].muchie || a[j][i].muchie)
                    MersCicluri(i, j);
    }

    void Grafuri_Orientate::AfisVPrietene()
    {
        int d1 = 0, d2= 0, cnt = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1 + i; j <= n; j++)
            {
                BFS(i);
                d1 = d[j];
                Reset();
                BFS(j);
                d2 = d[i];
                if(d1 == d2 && d1 != 0){
                    cnt = 1;
                    cout << i << " " << j << "\n";
                }
                Reset();
            }
        if(cnt == 0)
            cout << "Nu exista" << "\n";
    }

    void Grafuri_Orientate::Kosaraju()
    {
        SortTop();
        Reset();
        for (int i = n; i >= 1; i--)
            if (viz[v[i]] == 0)
            {
                nrctc++;
                DFS1(v[i]);
            }
    }

    void Grafuri_Orientate::AfisTC()
    {
        Kosaraju();
        cout << nrctc << "\n";
    }

    void Grafuri_Orientate::AfisArceInutile()
    {

        int cnt = 0;
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                if (viz[k] != viz[i]) cnt++;
        cout << cnt << "\n";
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                if (viz[k] != viz[i])
                    cout << k << " " << i << "\n";
    }

    void Grafuri_Orientate::Dijkstra(int k)
    {
        int i, mn;
        Reset();
        for (i = 1; i <= n; i++)
        {
            d[i] = oo;
            viz[i] = pred[i] = 0;
        }
        d[k] = 0;
        for (int pas = 1; pas <= n; pas++)
        {
            k = 0; mn = oo;
            for (i = 1; i <= n; i++)
                if (!viz[i] && d[i] < mn)
                {
                    mn = d[i];
                    k = i;
                }
            if (d[k] == oo) return;
            viz[k] = 1;
            for (i = 1; i <= n; i++)
                if (a[k][i].cost < oo && a[k][i].cost > 0 && d[i] > d[k] + a[k][i].cost)
                {
                    d[i] = d[k] + a[k][i].cost;
                    pred[i] = k;
                }
        }
    }

    void Grafuri_Orientate::Citire()
    {
        int i, j, c;
        cin >> n >> m;
        for(int p = 1; p <= m; p++)
        {
            cin >> i >> j >> c;
            a[i][j].muchie = 1;
            a[i][j].cost = c;
        }
    }

    void Grafuri_Orientate::AddMuchie(int i, int j)
    {
        a[i][j].muchie = 1;
    }

    void Grafuri_Orientate::AddMuchie(int i, int j, int c)
    {
        a[i][j].muchie = 1;
        a[i][j].cost = c;
    }

    void Grafuri_Orientate::StergeMuchie(int i, int j)
    {
        a[i][j].muchie = 0;
        a[i][j].cost = 0;
    }

    void Grafuri_Orientate::Grade()
    {
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
            {
                if(a[i][j].muchie)
                    di[i] += a[i][j].muchie;
                if(a[j][i].muchie)
                    de[i] += a[j][i] .muchie;
            }
    }

    void Grafuri_Orientate::TransferaMatriceInVector(int n, Graf a[Marime][Marime], KruskalStruct A[])
    {
        for (int i = 1; i <= n; i++)
         {
            for (int j = i + 1; j <= n; j++)
             {
                if (a[i][j].muchie == 1)
                {
                    A[m].x = i;
                    A[m].y = j;
                    A[m].c = a[i][j].cost;
                    A[m].viz = 0;
                }
            }
        }
    }

    void Grafuri_Orientate::Union(int x, int y)
    {
        t[y] = x;
    }

    bool Grafuri_Orientate::Compar(KruskalStruct e1, KruskalStruct e2)
    {
        return e1.c < e2.c;
    }

    int Grafuri_Orientate::Find(int x)
    {
        int rad = x, y;
        while(t[rad] != 0)
            rad = t[rad];
        while(x != rad)
        {
            y = t[x];
            t[x] = rad;
            x = y;
        }
        return rad;
    }

    void Grafuri_Orientate::Kruskal()
    {
        int x, y, nrcc = n;
        sort(a + 1, a + 1 + m, Compar);
        for(int i = 1; i <= m && nrcc > 1; i++)
        {
            x = Find(A[i].x);
            y = Find(A[i].y);
            if(x != y)
            {
                Union(x, y);
                nrcc--;
                A[i].viz = 1;
                costTotal += A[i].c;
            }
        }
    }

    void Grafuri_Orientate::AfisareKruskal()
    {
        cout << costTotal << "\n";
        for(int i = 1; i <= m; i++)
            if(A[i].viz)
                cout << A[i].x << " " << A[i].y << "\n";
    }

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
