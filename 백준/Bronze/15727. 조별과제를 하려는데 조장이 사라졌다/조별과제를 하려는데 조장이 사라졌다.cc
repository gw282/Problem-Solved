#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    if(n%5==0) cout << n/5;
    else cout << n/5+1;
}