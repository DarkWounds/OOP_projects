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

    /** Adauga un al k-lea de cheie x
        - daca k<=1, facem adaugarea la inceput
        - daca lista are mai putin de k noduri,
          atunci adaugam la final
    */
    void Add(int k, int x)
    {
        if (k <= 1)
        {
            Add(x);
            return;
        }
        Nod *p;
        for (p = head; p->leg != NULL && k > 2; p = p->leg)
            k--;
        Add(p, x);
    }

    /// ---------- redefinirea operatorilor -------------
    int operator[](int i)
    {
        if (head == NULL) return INT_MIN;
        if (i <= 0 || i > n) return INT_MIN;
        /// ne pozitionam pe al i-lea nod:
        Nod *p;
        for (p = head; i > 1; p = p->leg)
            i--;
        return p->info;
    }
    /**
    Daca la redefinirea operatorului avem mai multi parametri,
    atunci functia o definim ca friend.
    Functiile friend nu apartin clasei unde se definesc,
    dar se comporta ca si cum ar fi membre in clasa, adica
    au acces inclusiv la datele private.
    */
    friend bool operator==(LSI &A, LSI &B)
    {
        if (A.Count() != B.Count()) return 0;
        Nod *p = A.head, *q = B.head;
        while (p != NULL)
        {
            if (p->info != q->info) return 0;
            p = p->leg;
            q = q->leg;
        }
        return 1;
    }

    friend ostream& operator<<(ostream &out, LSI &A)
    {
        for (Nod *p = A.head; p != NULL; p = p->leg)
            out << p->info << " ";
        out << "\n";
        return out;
    }
    /// atribuirea
    LSI& operator=(LSI &A)
    {
        head = NULL;
        for (int i = 1; i <= A.Count(); i++)
            AddEnd(A[i]);
        return *this;
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
    w.Add(100, 112);
    w.Afis();
    w.Add(0, 666);
    w.Afis();
    w.Add(5, 888);
    w.Afis();
    /// afisare altfel:
    for (int i = 1; i <= w.Count(); i++)
        cout << w[i] << " ";

    LSI q;
    for (int i = 1; i <= w.Count(); i++)
        q.AddEnd(w[i]);

    cout << "\n\n";
    int v[] = {1,2,3,4,5,6,7};
    for (int i = 0; i < 7; i++)
        cout << i[v] << " ";

    if (w == q) cout << "Egale\n";
    else cout << "Diferite\n";

    cout << w;
    LSI x;
    x = w;
    cout << x;
    return 0;
}
