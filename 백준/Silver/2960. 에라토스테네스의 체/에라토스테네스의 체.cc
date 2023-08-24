/*
[2023-08-24 2960 에라토스테네스의 체]
*/
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k, cnt = 0;
    cin >> n >> k;

    int a[1002] = {0,};

    for(int i=2;i<=n;i++) {
        for(int j=i;j<=n;j+=i) {
            if(j % i == 0 && a[j] == 0) {
                cnt++;
                a[j] = 1;
            }
            if(cnt == k) {
                cout << j;
                return 0;
            }
        }
    }

}