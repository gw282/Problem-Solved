/*
[2023-08-08 9461 파도반 수열]
점화식: arr[i] = arr[i-1] + arr[i-5];
*/
#include <iostream>

using namespace std;

long long arr[102];

int t,n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 1;
    arr[4] = 2;
    arr[5] = 2;

    while(t--) {
        cin >> n;

        for(int i=6;i<=n;i++) {
            arr[i] = arr[i-1] + arr[i-5];
        }
        cout << arr[n] << '\n';
    }
}