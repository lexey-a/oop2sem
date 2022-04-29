#include <iostream>
using namespace std;
class Calculator
{
public:
    double Expression(double a, char x, double b);
};
int main()
{
    setlocale(LC_ALL, "ru");
    Calculator calc;
    while (true)
    {
        cout << "Введите выражение вида a X b, где X - один из знаков операции (+, -, *, /), a и b - операнды:\n";
        double a = 0.0;
        double b = 0.0;
        double result = 0.0;
        char x = '0';
        cin >> a >> x >> b;
        if ((cin.fail()) || (x != '+') || (x != '-') || (x != '*') || (x != '/'))
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Введен некорректный знак операции или операнд\n";
        }
        else
        {
            if ((b != 0.0) && (x != '/'))
            {
                result = calc.Expression(a, x, b);
                cout << a << x << b << '=' << result << '\n';
            }
            else
            {
                cout << "На ноль делить нельзя\n";
            }
        }

    }
}

double Calculator::Expression(double a, char x, double b)
{
    switch (x)
    {
    case '+':
        return (a + b);
    case '-':
        return (a - b);
    case '*':
        return (a * b);
    case '/':
        return (a / b);
    }
}
