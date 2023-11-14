#include <iostream>
using namespace std;

int main(void)
{
    char n[100];
    cin >> n;
    if (n[0] == 'A')
    {
        if (n[1] == '+')
            cout << "4.3";
        else if (n[1] == '0')
            cout << "4.0";
        else if (n[1] == '-')
            cout << "3.7";
    }
    else if (n[0] == 'B')
    {
        if (n[1] == '+')
            cout << "3.3";
        else if (n[1] == '0')
            cout << "3.0";
        else if (n[1] == '-')
            cout << "2.7";
    }
    else if (n[0] == 'C')
    {
        if (n[1] == '+')
            cout << "2.3";
        else if (n[1] == '0')
            cout << "2.0";
        else if (n[1] == '-')
            cout << "1.7";
    }
    else if (n[0] == 'D')
    {
        if (n[1] == '+')
            cout << "1.3";
        else if (n[1] == '0')
            cout << "1.0";
        else if (n[1] == '-')
            cout << "0.7";
    }
    else
        cout << "0.0";
}