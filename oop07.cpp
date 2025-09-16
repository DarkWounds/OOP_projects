#include <bits/stdc++.h>
using namespace std;

ifstream fin("intervale4.in");
ofstream fout("intervale4.out");

struct Interval
{
    int x, y;
};

template<class T>
class Stiva
{
private:
    T st[100002];
    int top;
public:
    Stiva()
    {
        top = 0;
    }

    void Init()
    {
        top = 0;
    }

    void Push(T x)
    {
        st[++top] = x;
    }

    void Pop()
    {
        top--;
    }

    T Top()
    {
        return st[top];
    }

    bool Empty()
    {
        return top == 0;
    }

    int Count()
    {
        return top;
    }
};

bool SeInt(Interval A, Interval B)
{
    if (A.y < B.x || A.x > B.y)
        return false;
    return true;
}

int main()
{
    Interval e;
    Stiva<Interval> a;
    int i, n;
    fin >> n;
    for (i = 1; i <= n; i++)
    {
        fin >> e.x >> e.y;
        /// scoatem din stiva toate intervalele
        /// care se intersecteaza cu e
        /// si facem reuniunea
        while (!a.Empty() && SeInt(e, a.Top()))
        {
            e.x = min(e.x, a.Top().x);
            e.y = max(e.y, a.Top().y);
            a.Pop();
        }
        a.Push(e);
    }
    fout << a.Count() << "\n";
    return 0;
}