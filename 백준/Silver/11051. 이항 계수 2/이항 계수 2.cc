/*
[2023-08-25 11051 이항 계수 2]
*/
#include <iostream>

using namespace std;

int arr[1002][1002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;

    cin >> n >> k;

    for(int i=1;i<=1000;i++) {
        arr[i][0] = 1; // nC0 = 1
        arr[i][i] = 1; // nCn = 1

        for(int j=1;j<i;j++) {
            arr[i][j] = (arr[i-1][j] + arr[i-1][j-1]) %10007;
            // nCk = n-1Ck + n-1Ck-1
        }
    }

    cout << arr[n][k];
}