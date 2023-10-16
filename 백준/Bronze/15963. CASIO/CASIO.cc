#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n,m;

    cin >> n >> m;

    if(n==m) cout << 1;
    else cout << 0;
}