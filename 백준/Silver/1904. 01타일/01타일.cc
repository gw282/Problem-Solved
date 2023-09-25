/*
[2023-09-25 1904]
*/
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int arr[1000002];

    cin >> n;
    
    arr[1] = 1;
    arr[2] = 2;
    
    for(int i=3;i<=n;i++) {
        arr[i] = (arr[i-2] + arr[i-1]) % 15746;
    }

    cout << arr[n];
}