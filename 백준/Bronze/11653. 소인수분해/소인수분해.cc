/*
[2023-08-24 11653 소인수분해]
*/
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    for(int i=2;i*2<=n;i++) {
        while(n%i == 0) {
            cout << i << '\n';
            n /= i;
        }
    }
    if(n!=1) cout << n;
}