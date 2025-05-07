#include <bits/stdc++.h>
using namespace std;
/// ----- Clasa listelor simplu inlantuite
class Nod
{
public:
    int info;
    Nod *leg;
    Nod(int cheie)
    {
        info = cheie;
        leg = NULL;
    }
};

class LSI
{
private:
    Nod *head;/// pointerul la inceputul listei
    int n; /// numarul de noduri din lista
public:
    /// ----------- Constructorii -----------
    LSI()
    {
        head = NULL;
        n = 0;
    }

    LSI(const char fisIn[])
    {
        int x;
        ifstream fin(fisIn);
        head = NULL;
        n = 0;
        /**
        while (fin >> x)
            AddEnd(x);
        */
        fin >> x;
        Add(x);
        Nod *p = head; /// p este un pointer la ultimul nod
        while (fin >> x)
        {
            Add(p, x);
            p = p->leg;
        }
        fin.close();
    }

    /// ----------- Destructorul ----------------
    ~LSI()
    {
        while (n > 0)
            Erase();
    }

    /// --------- Metodele -----------------
    /// adaugare la inceputul listei
    void Add(int cheie)
    {
        Nod *p = new Nod(cheie);
        p->leg = head;
        head = p;
        n++;
    }
    /// adauga dupa nodul p un nou nod de cheie data
    void Add(Nod *p, int cheie)
    {
        Nod *q = new Nod(cheie);
        q->leg = p->leg;
        p->leg = q;
        n++;
    }

    /// sterge primul nod
    void Erase()
    {
        if (head == NULL) return;
        Nod *p = head;
        head = head->leg;
        delete p;
        n--;
    }

    /// sterge nodul de dupa p
    void Erase(Nod *p)
    {
        if (p->leg == NULL) return;
        Nod *q = p->leg;
        p->leg = q->leg;
        delete q;
        n--;
    }

    void Afis()
    {
        for (Nod *p = head; p != NULL; p = p->leg)
            cout << p->info << " ";
        cout << "\n\n";
    }

    int Count()
    {
        return n;
    }

    void AddEnd(int cheie)
    {
        if (head == NULL)
        {
            Add(cheie);
            return;
        }
        /// ne pozitionam pe ultimul nod, apoi inseram dupa el
        Nod *p = head;
        while (p->leg != NULL)
            p = p->leg;
        Add(p, cheie);
    }

    /** Adauga cheia x dupa al k-lea nod
        - daca k<=1, facem adaugarea la inceput
        - daca lista are mai putin de k noduri,
          atunci adaugam la final
    */
    void Add(int k, int x)
    {
        if(k <= 1)
            Add(x);
        else if (k >= n)
            AddEnd(x);
        else
        {
            Nod *p = head;
            while(k > 1)
            {
                k--;
                p = p -> leg;
            }
            Add(p, x);
        }

    }
};

int main()
{
    LSI L;
    for (int i = 20; i >= 1; i--)
        L.Add(i * i);
    L.Afis();
    cout << L.Count() << "\n";
    L.AddEnd(777);
    L.Afis();
    cout << L.Count() << "\n";

    LSI w("lista.in");
    w.Afis();

    L.Add(5, 505);
    L.Afis();
    return 0;
}