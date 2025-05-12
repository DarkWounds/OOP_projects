#include <bits/stdc++.h>
using namespace std;

///ifstream fin("intervale4.in");
///ofstream fout("intervale4.out");

template<class T>
class Stiva
{
private:
    T st[1000002];
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
    void Afis()
    {
        for(int i = 1; i <= top; i++)
            cout << st[i];
        cout << "\n";
    }
};

int main()
{
    string s;
    int k;
    Stiva<char> a;
    cin >> k >> s;
    for(int i = 0; i < s.size(); i++)
    {
        while(!a.Empty() && s[i] < a.Top() && k > 0)
        {
            a.Pop();
            k--;
        }
        a.Push(s[i]);
    }
    while(k--) a.Pop();
    a.Afis();
    return 0;
}