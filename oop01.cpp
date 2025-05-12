#include <iostream>

using namespace std;


/**
Intr-o clasa se afla urmatoarele date membre:
- variabile membre = variabile definite in clasa
- functii membre (metode - methods) = functii
  definite in interiorul clasei
- constructori
- destructor
- operatori redefiniti

Accesul la datele membre ale clasei:
- private : datele private pot fi accesate NUMAI in
  interiorul clasei
- public: datele publice pot fi accesate si din afara clasei
- protected: sunt datele care se comporta precum cele
   private, dar sunt accesibile si din clasele derivate
Obs1:Daca nu este specificat pentru o data membra care este
tipul de acces, atunci implicit acea data membra este private

Obs2: si datele membre ale unei structuri au aceleasi
tipuri de acces, dar implicit accesul este public.
*/
/// clasa numerelor rationale
/// Q = {a/b, a,b apartin lui Z, b!=0}
class Rational
{
public:
    int a; /// numaratorul - var membra
    int b; /// numitorul - var membra
    void Afis(); /// functie membra, sau Metoda
    void Init(int val_a, int val_b);
    void Init(int v);
    void Produs(Rational X, Rational Y);
    void Aduna(Rational X, Rational Y);
    int CmmdcRec(int x, int y);
    int Cmmdc(int x, int y);
};
/**
:: - operator de apartenenta la o clasa
   - Scope Resolution (operator de scop)
*/
int Rational::CmmdcRec(int x, int y)
    {
        if (y == 0) return x;
        return CmmdcRec(y, x % y);
    }

    int Rational::Cmmdc(int x, int y)
    {
        int r;
        while (y != 0)
        {
            r = x % y;
            x = y;
            y = r;
        }
        return x;
    }
void Rational::Aduna(Rational X, Rational Y)
    {
        a = X.a * Y.b + X.b * Y.a;
        b = X.b * Y.b;
        int c  = CmmdcRec(a, b);
        a /= c;
        b /= c;
    }

void Rational::Afis()
{
    cout << a << " / " << b << "\n";
}
void Rational::Init(int val_a, int val_b)
    {
        a = val_a;
        b = val_b;
    }
void Rational::Init(int v)
    {
        a = b = v;
    }
void Rational::Produs(Rational X, Rational Y)
    {
        a = X.a * Y.a;
        b = X.b * Y.b;
        int c  = CmmdcRec(a, b);
        a /= c;
        b /= c;
    }

int main()
{
    Rational p, q, r;
    p.Init(2,3);
    q.Init(4);
    p.Afis();
    q.Afis();
    r.Aduna(p, q);
    r.Afis();
    r.Produs(p, q);
    r.Afis();
    return 0;
}
