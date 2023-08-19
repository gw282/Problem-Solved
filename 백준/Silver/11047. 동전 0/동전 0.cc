/*
[2023-08-19 11047 동전 0]
동전을 최소로 쓰면서 물건값을 맞추려면 큰 금액의 동전을 더 많이 사용해야함
*/
#include <iostream>

using namespace std;

int n, k;

int arr[12];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }

    int cnt = 0;

    for(int i=n;i>=1;i--) {
        if(arr[i]<=k) {
            cnt += k / arr[i];
            k %= arr[i];
        }
    }
    cout << cnt;
}