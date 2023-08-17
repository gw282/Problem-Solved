/*
[2023-08-17 11055 가장 큰 증가하는 부분 수열]
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n,mx,tmp;

int arr[1002],cnt[1002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }

    arr[0] = 0;
    cnt[0] = 0;

    for(int i=1;i<=n;i++) {
        tmp = 0;
        for(int j=0;j<i;j++) {
            if(arr[i]>arr[j]) { // 이전에 나왔던 수가 현재수보다 작으면
                tmp = arr[i] + cnt[j]; // 이전 수 최댓값 배열과 현재 수를 합산
                cnt[i] = max(tmp, cnt[i]); // 현재 수 최댓값 배열과 값 비교
            }
        }
    }

    mx = *max_element(cnt, cnt+n+1);
    cout << mx;
}