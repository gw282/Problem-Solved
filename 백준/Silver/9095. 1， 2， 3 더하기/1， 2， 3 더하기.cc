/*
[2023-08-13 9095 1,2,3 더하기]
현재 수 = 이전 수 3개의 경우의 수의 합.
*/
#include <iostream>

using namespace std;

int n, t;
int arr[13];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    
    for(int i=4;i<12;i++) {
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    }
    while(t--) {
        cin >> n;
        cout << arr[n] << '\n';
    }
}