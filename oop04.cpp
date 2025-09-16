
#include <bits/stdc++.h>
using namespace std;

/**
Destructorul
------------
- O clasa are un singur destructor
- Daca nu s-a definit un destructor, atunci va exista unul
  implicit
- Rolul destructorului este de eliberare a memoriei
- Poarta numele clasei, precedat de semnul ~
- Nu returneaza nimic, nici macar void si nu are parametri
- Destructorul se apeleaza implicit, cand obiectul isi
  inceteaza existenta.
*/

class Vector
{
private:
    int *a; /// pointer asociat unui vector nealocat
    int n; /// dimensiunea logica a lui a
    int N; /// dimensiunea fizica a lui a, putere a lui 2
    /// n <= 2^k=N
public:
    /// ------ Destructorul -----------
    ~Vector()
    {
        delete[] a;
        n = 0; N = 1;
    }

    /// ------- Constructori --------------------
    /// facem un vector de dim logica egala cu dim
    /// si care este initializat cu 0 peste tot
    Vector(int dim)
    {
        n = dim;
        for (N = 1; N < n; N *= 2)
            ;
        a = new int[N];
        for (int i = 0; i < n; i++)
            a[i] = 0;
    }
    /// facem un vector de dim logica egala cu dim
    /// si care este initializat cu val peste tot
    Vector(int dim, int val)
    {
        n = dim;
        for (N = 1; N < n; N *= 2)
            ;
        a = new int[N];
        for (int i = 0; i < n; i++)
            a[i] = val;
    }
    Vector()
    {
        n = 0; N = 1;
        a = new int[N];
    }
    /// constructor de copiere
    Vector(Vector &v)
    {
        n = v.n;
        N = v.N;
        a = new int[N];
        for (int i = 0; i < n; i++)
            a[i] = v.a[i];
    }
    Vector(const char fisIn[])
    {
        int x;
        ifstream fin(fisIn);
        n = 0; N = 1;
        a = new int[N];
        while (fin >> x)
            PushBack(x);
        fin.close();
    }
    ///------- Final sectiune constructori ------------

    /// ------- Functii membre (metode) -----------
    void Afis()
    {
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << "\n";
    }
    /// adauga la finalul lui a un element x
    void PushBack(int x)
    {
        if (n == N)
        {
            /// a = 4,3,2,5 x 0 0 0
            /// b = 4,3,2,5
            int *b;
            b = new int[N];
            for (int i = 0; i < n; i++)
                b[i] = a[i];
            delete[] a;
            N *= 2;
            a = new int[N];
            for (int i = 0; i < n; i++)
                a[i] = b[i];
        }
        a[n++] = x;
    }

    int Size()
    {
        return n;
    }
    /// sterge elementul de la pozitia p
    void Erase(int p)
    {
        if (p < 0 || p >= n) return;
        for (int i = p; i < n - 1; i++)
            a[i] = a[i + 1];
        n--;
    }
    /// sterge a[st..dr]
    void Erase(int st, int dr)
    {
        if (st < 0) st = 0;
        if (dr >= n) dr = n - 1;
        for (int i = dr + 1; i < n; i++)
            a[st++] = a[i];
        n = st;
    }

    int ValMax()
    {
        if (n == 0) return INT_MIN;
        int mx = a[0];
        for (int i = 1; i < n; i++)
            mx = max(mx, a[i]);
        return mx;
    }
    /// adauga la pozitia p valoarea val
    void Insert(int p, int val)
    {
        if (p < 0) p = 0;
        if (p > n) p = n;
        if (n < N)
        {
            for (int i = n; i > p; i--)
                a[i] = a[i - 1];
            a[p] = val;
            n++;
        }
        else
        {
            int i, *b;
            b = new int[N];
            for (i = 0; i < n; i++)
                b[i] = a[i];
            delete[] a;
            N *= 2;
            a = new int[N];
            for (i = 0; i < p; i++)
                a[i] = b[i];
            a[p] = val;
            for (i = p; i < n; i++)
                a[i + 1] = b[i];
            n++;
        }
    }

    void Sortare()
    {
        sort(a, a + n);
    }

    void Sortare(int st, int dr)
    {
        sort(a + st, a + dr + 1);
    }

    void SortDesc()
    {
        sort(a, a + n, greater<int>());
    }

    void SortDesc(int st, int dr)
    {
        sort(a + st, a + dr + 1, greater<int>());
    }

    int CautarePozMin()
    {
        if (n == 0) return -1;
        int i, p = 0;
        for (i = 1; i < n; i++)
            if (a[i] < a[p]) p = i;
        return p;
    }

    int CautarePozMax()
    {
        if (n == 0) return -1;
        int i, p = 0;
        for (i = 1; i < n; i++)
            if (a[i] > a[p]) p = i;
        return p;
    }

    /// cauta prima aparitie a lui x in a
    int IndexOf(int x)
    {
        for (int i = 0; i < n; i++)
            if (a[i] == x) return i;
        return -1;
    }

    /// cauta ultima aparitie a lui x in a
    int LastIndexOf(int x)
    {
        for (int i = n - 1; i >= 0; i--)
            if (a[i] == x) return i;
        return -1;
    }

    /// cauta o pozitie unde apare valoarea x
    int CautBin(int x)
    {
        int st, dr, mid;
        st = 0; dr = n - 1;
        while (st <= dr)
        {
            mid = (st + dr) / 2;
            if (a[mid] == x) return mid;
            if (a[mid] < x) st = mid + 1;
            else dr = mid - 1;
        }
        return -1;
    }

    /// cauta prima pozitie p unde apare valoarea x
    int CautBinLeft(int x)
    {
        int st, dr, mid, p = -1;
        st = 0; dr = n - 1;
        while (st <= dr)
        {
            mid = (st + dr) / 2;
            if (a[mid] == x)
            {
                p = mid;
                dr = mid - 1;
            }
            if (a[mid] < x) st = mid + 1;
            else dr = mid - 1;
        }
        return p;
    }
    /// cauta ultima pozitie p unde apare valoarea x
    int CautBinRight(int x)
    {
        int st, dr, mid, p = -1;
        st = 0; dr = n - 1;
        while (st <= dr)
        {
            mid = (st + dr) / 2;
            if (a[mid] == x)
            {
                p = mid;
                st = mid + 1;
            }
            if (a[mid] < x) st = mid + 1;
            else dr = mid - 1;
        }
        return p;
    }
};

int main()
{
    Vector A;
    int i, x, n, m, p;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> x;
        A.PushBack(x);
    }
    cin >> m;
    for (i = 1; i <= m; i++)
    {
        cin >> x;
        p = A.CautBin(x);

        if (p == -1) p = 0;
        else p = 1;
        cout << p << " ";
    }
    return 0;
}
