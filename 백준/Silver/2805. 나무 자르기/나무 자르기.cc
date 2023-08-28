/*
[2023-08-28 2805 나무 자르기]
*/
#include <iostream>
#include <algorithm> // max_element

using namespace std;

int n,m;
int arr[1000002];

bool flag(int num) {
    long long cnt = 0;
    for(int i=0;i<n;i++) {
        if(arr[i] <= num) continue; // 잘라야하는 길이가 나무 길이보다 큰 경우 pass
        cnt += (arr[i] - num); // 자르고 남은 길이를 합한다
    }
    return cnt >= m; // 총 합이 m을 넘어야함
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    int st = 0;
    int en = *max_element(arr,arr+n);

    while(st < en) { // 가장 긴 길이의 나무를 기준으로 binary search
        int mid = (st+en+1) / 2;
        if(flag(mid)) st = mid;
        else en = mid - 1;
    }
    cout << st;
}