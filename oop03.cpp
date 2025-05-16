#include <bits/stdc++.h>
using namespace std;

class Stiva
{
private:
    int s[2000000], top = 0, mx = -2e9;
public:
    void Push(int x)
    {
        s[++top] = x;
        mx = max(s[top], mx);
    }
    void Pop()
    {
        if(s[top] == mx) Max1();
        else top--;
    }
    int Top()
    {
        if(Empty()) return -1;
        return s[top];
    }
    int Max()
    {
        return mx;
    }
    void Max1()
    {
        if(!Empty())
        {
            top--;
            int top1 = top; mx = -2e9;
            while(top1 != 0)
            {
                if(s[top1] > mx) mx = s[top1];
                top1--;
            }
        }
    }
    int Empty()
    {
        if(top == 0) return 1;
        return 0;
    }
};

int main()
{
    return 0;
}