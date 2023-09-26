/*
[2023-09-26 1788]
*/
#include <iostream>
#include <cstdlib>

using namespace std;

long long fibo(int n) {
    long long arr[1000001];

    arr[0] = 0;
    arr[1] = 1;

    for(int i=2; i<=n;i++) {
        arr[i] = (arr[i-1] + arr[i-2]) % 1000000000;
    }
    return arr[n] % 1000000000;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;

    if(n>0) {
        cout << 1 << '\n' << fibo(n);
    }
    else if(n<0) {
        n *= -1;
        if(n%2 == 0) cout << -1 << '\n';
        else cout << 1 << '\n';
        cout << fibo(n);
    }
    else {
        cout << 0 << '\n' << 0;
    }
}