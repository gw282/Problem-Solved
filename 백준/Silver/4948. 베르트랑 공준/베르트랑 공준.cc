/*
[2023-08-26 4948 베르트랑 공준]
*/
#include <iostream>

using namespace std;

int arr[250000] ={0,};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,cnt;

    while(1) {
        cin >> n;

        cnt = 0;
        arr[1] = 0;

        if(n == 0) return 0;

        for(int i=2;i*i<=2*n;i++) {
            if(arr[i] != 1) {
                for(int j=i*2;j<=2*n;j+=i) {
                    arr[j] = 1;
                }
            }
        }
        for(int i=n+1;i<=2*n;i++) { // n+1 ~ 2n까지 탐색
            if(arr[i] != 1) {
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
}