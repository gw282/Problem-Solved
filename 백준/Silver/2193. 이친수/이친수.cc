/*
[2023-08-15 2193 이친수]
*/
#include <iostream>

using namespace std;

int n;
long long arr[100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    arr[1] = 1;
    arr[2] = 1;

    for(int i=3;i<=n;i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }
    cout << arr[n];
}