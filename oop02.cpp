#include <bits/stdc++.h>
using namespace std;

/**
Constructorii
---------------
- Au rol de initializare
- Pot exista oricati constructori intr-o clasa, care difera prin
  numarul si tipul parametrilor
- Poarta numele clasei
- Nu returneaza nimic, nici macar void
- Fiind membri ai clasei, constructorii pot fi
   private, protected, public
- Se apeleaza implicit
- Constructorii pot fi:
    - constructor de copiere (Copy Constructor)
    - constructor implicit (Default Constructor)
    - alti constructori
- Daca o clasa nu are niciun constructor, atunci de defineste
  unul in mod implicit
*/

class Complex
{
private:
    double re, im; /// partile reala si imaginara
public:
    Complex() /// constructorul implicit
    {
        Init();
    }
    Complex(double x, double y) /// categoria "alti constr."
    {
        Init(x,y);
    }
    Complex(Complex &z) /// constructor de copiere
    {
        re = z.re; im = z.im;
    }
    Complex(string fisIn)
    {
        ifstream fin(fisIn);
        fin >> re >> im;
        fin.close();
    }
    void Init()
    {
        re = im = 0;
    }
    void Init(double x, double y)
    {
        re = x;
        im = y;
    }
    void Afis()
    {
        cout << re << " + i * " << im << "\n";
    }
    void Aduna(Complex z1, Complex z2)
    {
        re = z1.re + z2.re;
        im = z1.im + z2.im;
    }
    void Inmultire(Complex z1, Complex z2)
    {
        re = z1.re * z2.re - z1.im * z2.im;
        im = z1.re * z2.im + z1.im * z2.re;
    }

    void Impartire(Complex z1, Complex z2)
    {
        re = (z1.re * z2.re + z1.im * z2.im) / ModulP();
        im = (z1.im * z2.re - z1.re * z2.im) / ModulP();
    }

    double Modul()
    {
        return sqrt(re * re + im * im);
    }

    double ModulP() /// modulul la patrat
    {
        return re * re + im * im;
    }
    double Re()
    {
        return re;
    }
    double Im()
    {
        return im;
    }
};

int main()
{
    Complex z, z1(2, 3), z2(5,2); /// obiecte
    z1.Afis();
    z2.Afis();
    z.Aduna(z1, z2);
    z.Afis();
    z.Inmultire(z1, z2);
    z.Afis();
    z.Impartire(z1, z2);
    z.Afis();
    cout << "Partea reala este : " << z.Re() << "\n";
    cout << "Partea imaginara este : " << z.Im() << "\n";

    Complex z3(z1); /// s-a apelat implicit constructorul de copiere
    z1.Afis();
    z3.Afis();

    Complex z4("c.in");
    z4.Afis();
    return 0;
}