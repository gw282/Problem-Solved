/*
[2023-08-08 15652 카드]
수의 범위가 2^62이므로 long long 사용
배열에 수의 빈도수를 저장하는 것이 아닌
배열에 수 자체를 입력받은 뒤 정렬 -> 빈도수 높은 수를 계속해서 갱신
*/
#include <iostream>
#include <algorithm>
using namespace std;

long long arr[100002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    stable_sort(arr,arr+n);

    int cnt = 0;
    int max_cnt = 0;
    long long max_num;

    for(int i=0;i<n;i++) {
        if(i==0 || arr[i-1]==arr[i]) {
            cnt++;
        }
        else { // 이전 수와 현재 수가 다름
            if(cnt > max_cnt) {
                max_cnt = cnt;
                max_num = arr[i-1];
            }
            cnt = 1; // arr[i]에 대한 카운팅
        }
    }
    if(cnt > max_cnt) { // 마지막 수를 기존 값과 비교
        max_num = arr[n-1];
    }

    cout << max_num;
}