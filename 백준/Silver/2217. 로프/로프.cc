/*
[2023-08-21 2217 로프]
정렬한 다음 제일 작은 수 * n 하면 끝!
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n;

int arr[100002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int mx = 0;

    cin >> n;

    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    stable_sort(arr,arr+n);

    for(int i=0;i<n;i++) {
        mx = max(mx, (arr[i]*(n-i)));
    }
    cout << mx;
}