/*
[2023-08-27 16401 과자 나눠주기]
*/
#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000002];
int m, n;

bool flag(int num) {
    if(num == 0) return true;
    long long cnt = 0;
    for(int i=1;i<=n;i++) {
        cnt += arr[i] / num;
    }
    return cnt >= m; // 막대과자 개수가 m보다 큰 경우 true
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }
    int st = 0;
    int en = *max_element(arr+1, arr+n+1);

    while(st < en) {
        int mid = (st+en+1) / 2;
        if(flag(mid)) st = mid; // 길이가 더 큰 경우가 있는지 확인
        else en = mid - 1; // 길이가 더 작아져야됨
    }
    cout << st;

}