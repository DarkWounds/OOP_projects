#include <bits/stdc++.h>
using namespace std;

/**
clasa Stiva - template
*/
template<class T>
class Stiva
{
private:
    T st[1002];
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
        if(top > 0)
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

int main()
{
    int n, i, x;
    string op;
    Stiva<int> a;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> op;
        if (op == "push")
        {
            cin >> x;
            a.Push(x);
        }
        else if (op == "pop")
        {
            a.Pop();
        }
        else /// op == "top"
        {
            if (!a.Empty())
                cout << a.Top() << "\n";
        }
    }

    return 0;
}