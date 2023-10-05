#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long n=1, m=1;

    while(1) {
        cin >> n >> m;
        if(n==0 && m==0) return 0;
        if(n>m) cout << "Yes\n";
        else cout << "No\n";
    }
}