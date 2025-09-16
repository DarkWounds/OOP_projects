#include <bits/stdc++.h>
using namespace std;

/**
Datele statice
---------------
- variabile statice
- functii statice

Datele statice dintr-o clasa nu apartin unui anumit obiect,
ci sunt comune tuturor obiectelor.

Un rol important al variabielor statice ale unei clase este de a
contoriza obiectele.
*/

class SuccesMaxim
{
public:
    int pix;
    static int carioca;

    void Init()
    {
        pix = 0;
        carioca = 0;
    }

    void Inc()
    {
        pix++;
        carioca++;
    }

    void Afis()
    {
        cout << pix << " " << carioca << "\n";
    }

    static int NrObiecte()
    {
        return carioca;
    }
};

int SuccesMaxim :: carioca = 0;/// asa se initializeaza o variabila statica

int main()
{
    SuccesMaxim A, B, C;
    A.Init();
    B.Init();
    C.Init();
    A.Inc(); A.Afis();
    B.Inc(); B.Afis();
    C.Inc(); C.Afis();
    cout << SuccesMaxim :: NrObiecte() << "\n";
    return 0;
}