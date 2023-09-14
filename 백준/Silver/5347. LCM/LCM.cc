/*
[2023-09-14 9655 lcm
*/
#include <iostream>

using namespace std;

long long gcd(int n, int m) {
    if(n==0) return m;
    return gcd(m%n, n);
}

long long lcm(int n, int m) {
    return n / gcd(n,m) * m;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;
    
    cin >> n;

    while(n--) {
        cin >> a >> b;
        cout << lcm(a,b) << '\n';
    }
}