#include <bits/stdc++.h>
#define pi 4 * atan(1)
using namespace std;

/**
Polimorfism
------------
Polimorfismul se refera la faptul ca o functie poate lua
mai multe forme. De exemplu, formula ariei unui cerc difera de
formula ariei unui patrat sau de a unui dreptunghi, dar toate
functiile le numim Aria().
Deci nu este vorba de supra-incarcarea functiilor!
*/

class FormeGeom
{
public:
    FormeGeom()
    {  }

    virtual double Aria()
    {
        return 0;
    }
    virtual double Volum()
    {
        return 0;
    }
    virtual void Afis()
    {
        cout << "Forme geometrice\n";
    }
};

class Cerc : public FormeGeom
{
public:
    double raza;
    Cerc(double _r)
    {
        raza = _r;
    }
    virtual double Aria()
    {
        return pi * raza * raza;
    }
    virtual double Peri()
    {
        return 2 * pi * raza;
    }
    virtual void Afis()
    {
        cout << "Cerc\n";
    }
};

class Cilindru : public Cerc
{
public:
    double h;
    Cilindru(double _r, double _h) : Cerc(_r)
    {
        h = _h;
    }

    virtual double Aria()
    {
        return Peri() * h + 2 * pi * raza * raza;
    }

    virtual double Volum()
    {
        return pi * raza * raza * h;
    }
    virtual void Afis()
    {
        cout << "Cilindru\n";
    }
};

int main()
{
    FormeGeom fg;

    Cerc c(3);
    cout << "Aria = " << c.Aria() << "\n";
    cout << "Perimetrul = " << c.Peri() << "\n";

    Cilindru d(3, 5);
    cout << "Aria cil = " << d.Aria() << "\n";
    cout << "Volum cil = " << d.Volum() << "\n";

    FormeGeom *f1 = new FormeGeom;
    FormeGeom *f2 = new Cerc(3);
    FormeGeom *f3 = new Cilindru(3, 5);

    cout << f1->Aria() << "\n";
    cout << f2->Aria() << "\n";
    cout << f3->Aria() << "\n";

    f1->Afis();
    f2->Afis();
    f3->Afis();

    return 0;
}
