/*
[2023-09-18 1735 분수 합]
*/
#include <iostream>

using namespace std;

long long gcd(int a, int b) {
    if(a==0) return b;
    return gcd(b%a,a);
}

long long lcm(int a, int b) {
    return a / gcd(a,b) * b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long a1, a2, b1, b2;
    long long res1 , res2;

    cin >> a1 >> a2 >> b1 >> b2;
    int a = gcd(a1,a2);
    int b = gcd(b1,b2);
    a1 = a1/a;
    a2 = a2/a;
    b1 = b1/b;
    b2 = b2/b;

    res2 = lcm(a2, b2);

    res1 = res2/a2 * a1 + res2/b2 * b1;
    
    int g = gcd(res2,res1);
    res2 = res2 / g;
    res1 = res1 / g;


   cout << res1 << ' ' << res2;
}