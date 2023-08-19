/*
[2023-08-19 11399 ATM]
정렬한 뒤 누적합을 한다
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n;

int arr[1002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt = 0;

    cin >> n;

    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }

    stable_sort(arr+1,arr+n+1);

    for(int i=1;i<=n;i++) {
        arr[i] = arr[i] + arr[i-1];
        cnt += arr[i];
    }

    cout << cnt;
}