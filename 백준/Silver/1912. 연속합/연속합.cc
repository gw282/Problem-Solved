/*
[2023-08-15 1912 연속합]
이전항 + 현재항 vs 현재항과 비교해서 큰값을 배열에 저장한다
이전항 + 현재항이 더 크면 연속합 진행
현재항이 더 크면 현재항부터 연속합 진행
즉 이전의 연속합이 음수가 된다면 현재항부터 더하는 게 최댓값이 된다
*/
#include <iostream>

using namespace std;

int n,mx;
int arr[100002];
int arr2[100002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=1;i<=n;i++) {
        cin >> arr[i];
        arr2[i] = arr[i];
    }

    for(int i=1;i<=n;i++) {
        arr[i] = max(arr[i],arr[i-1]+arr2[i]); // 이전항 + 현재항 vs 현재항 비교
    }

    mx = arr[1];
    for(int i=2;i<=n;i++) {
        mx = max(mx,arr[i]); // 배열 안의 최댓값 출력
    }

    cout << mx;
}