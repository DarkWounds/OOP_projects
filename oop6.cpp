#include <bits/stdc++.h>
using namespace std;

/**
Template
--------
Definim un template (sablon)
pentru tipul elementelor (care este T)
si dimensiunea vectorului (n) pentru
calculul sumei elementelor unui vector
*/
template <class T, int n>
T Suma(T vector[])
{
    T suma = 0;
    for (int i = 0; i < n; i++)
        suma += vector[i];
    return suma;
}

int main()
{
    int v[] = {4,2,6,1,2,5,8};
    int t[] = {1,2,3,4,5,6,7,8,9};
    cout << Suma<int, 4>(v) << "\n";
    cout << Suma<int, 7>(v) << "\n";
    cout << Suma<int, 6>(t) << "\n";
    cout << Suma<int, 9>(t) << "\n";

    long long a[] = {1000000000, 2000000000, 1000000000, 2000000000};
    cout << Suma<long long, 4>(a) << "\n";
    return 0;
}