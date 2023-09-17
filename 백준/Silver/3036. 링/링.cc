/*
[2023-09-17 3036 링]
*/
#include <iostream>

using namespace std;

long long gcd(int a, int b) {
    if(a == 0) return b;
    return gcd(b%a, a);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, base, num;
    cin >> n >> base;
    n = n-1;
    while(n--) {
        cin >> num;
        cout << base / gcd(base, num) << '/' << num / gcd(base, num) << '\n';
    }
}