#include <bits/stdc++.h>
using namespace std;

/**
Evaluarea expresiilor aritmetice

Programului i se introduce o expresie aritmetica cu operatorii +, -, *, /, iar acesta
afiseaza raspunsul corect. In rezolvarea problemei, el foloseste o clasa in care sunt
introduse 4 functii principale (Tokenize, Postfix, EvalPostfix, Eval). Tokenize este functia
care tranforma fiecare element din expresie intr-un "jeton" individual pentru ca in
Postfix, aceste elemente sa fie aranjate convenabil intr-un vector, in notatie postfixa
(forma poloneza a unei expresii). EvalPostfix este cea care manevreaza elementele
din vectorul aranjat in ordine postfixa si rezolva expresia, cu ajutorul unei stive.
In final, Eval pune cap la cap cele 3 functii precedente si ofera rezultatul final.
In cazul in care expresia nu este scrisa corect, se vor afisa diferite avertismente.
*/

class Eval_Expr
{
private:
    map<char, int> pr;

    bool Op(char c)
    {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }

    bool Space(char c)
    {
        return c == ' ';
    }

    bool IsNumber(string& s)
    {
        if (s.empty()) return false;
        int i = 0;
        if (s[0] == '-') i++;
        bool hasDigits = false;
        for (; i < s.size(); i++)
        {
            if (!isdigit(s[i]) && s[i] != '.') return false;
            if (isdigit(s[i])) hasDigits = true;
        }
        return hasDigits;
    }

    bool HighPr(char op1, char op2) ///testeaza prioritatea a doi operatori
    {
        return pr[op1] >= pr[op2];
    }

    ///separam elementele din string in token-uri (jetoane)
    /// ex: -112 + 7 * (2 - 11) -> {"-112", "+", "7", "*", "(", "2", "-", "11", ")"}
    vector<string> Tokenize(string& s)
    {
        vector<string> tokens;
        int n = s.size(), i;
        for(i = 0; i < n; )
        {
            if (Space(s[i]))
            {
                i++;
                continue;
            }
            ///pentru cazurile -5 + 12..., -(7 + 13) / 2 , -7 / -2, etc
            if ((s[i] == '-' || s[i] == '+') && (i == 0 || (s[i - 1] == '(' || Op(s[i - 1]))))
            {
                string num(1, s[i++]);
                while (i < n && (isdigit(s[i]) || s[i] == '.'))
                    num += s[i++];
                tokens.push_back(num);
                continue;
            }
            if (isdigit(s[i]) || s[i] == '.')
            {
                string num;
                while (i < n && (isdigit(s[i]) || s[i] == '.'))
                    num += s[i++];
                tokens.push_back(num);
            }
            else if (s[i] == '(' || s[i] == ')' || Op(s[i])) tokens.push_back(string(1, s[i++]));
            else
            {
                cout << "Caracter invalid: " << s[i] << "\n";
                exit(1);
            }
        }
        return tokens;
    }

    ///aranjeaza vectorul tokens in notatia postfixa, prin algoritmul Shunting Yard
    ///exemplu 1: {"2", "-", "5", "*", "3"} => {"2", "5", "3", "*", "-"}
    ///exemplu 2: {"2", "+", "3", "-", "(", "6", "-", "2", ")", "/", "4"} => {"2", "3", "+", "6", "2", "-", "4", "/", "-"}
    vector<string> Postfix(vector<string>& tokens)
    {
        vector<string> rez;
        stack<string> st;
        for(string t : tokens)
        {
            if(IsNumber(t)) rez.push_back(t);
            else if (t == "(") st.push(t);
            else if (t == ")")
            {
                while(!st.empty() && st.top() != "(")
                {
                    rez.push_back(st.top());
                    st.pop();
                }
                if (!st.empty()) st.pop();
            }
            else
            {
                while (!st.empty() && Op(st.top()[0]) && HighPr(st.top()[0], t[0]))
                {
                    rez.push_back(st.top());
                    st.pop();
                }
                st.push(t);
            }
        }
        while (!st.empty())
        {
            rez.push_back(st.top());
            st.pop();
        }
        return rez;
    }

    ///calculeaza valoarea finala a expresiei sau afiseaza posibilele erori acolo unde este cazul
    double EvalPostfix(vector<string>& postfix)
    {
        stack<double> st;
        for (string token : postfix)
        {
            if (IsNumber(token)) st.push(stod(token));
            else if (Op(token[0]) && token.size() == 1)
            {
                if (st.size() < 2)
                {
                    cout << "Expresie invalida.\n";
                    exit(1);
                }
                double b = st.top(); st.pop();
                double a = st.top(); st.pop();
                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else if (token == "/")
                {
                    if (b == 0)
                    {
                        cout << "Eroare: impartire la 0\n";
                        exit(1);
                    }
                    st.push(a / b);
                }
            }
            else
            {
                cout << "Element necunoscut: " << token << "\n";
                exit(1);
            }
        }

        if (st.size() != 1)
        {
            cout << "Eroare la evaluare.\n";
            exit(1);
        }

        return st.top();
    }

public:
    Eval_Expr()
    {
        pr['+'] = 1;
        pr['-'] = 1;
        pr['*'] = 2;
        pr['/'] = 2;
    }

    double Eval(string& expr)
    {
        vector<string> tokens = Tokenize(expr);
        vector<string> postfix = Postfix(tokens);
        return EvalPostfix(postfix);
    }
};

int main()
{
    Eval_Expr evaluator;
    string expresie;
    cout << "Introdu o expresie aritmetica:\n";
    getline(cin, expresie);
    double rezultat = evaluator.Eval(expresie);
    cout << "Rezultatul este: " << rezultat << "\n";
    return 0;
}
