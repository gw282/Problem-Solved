/*
[2023-09-11 25591 푸앙이와 종윤이]
*/
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    int a,b,c,d,q,r;

    cin >> n >> m;

    a = 100 - n;
    b = 100 - m;

    c = 100 -(a+b);

    d = a * b;

    q = d / 100;
    r = d % 100;

    cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << q << ' ' << r << '\n';
    cout << c+q << ' ' << r;
}