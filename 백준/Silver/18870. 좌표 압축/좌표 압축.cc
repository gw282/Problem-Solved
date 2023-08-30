/*
[2023-08-08 18870 좌표 압축]
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[1000002]; // 입력 받은 배열
int arr2[1000002]; // 정렬을 거칠 배열
vector <int> v; // 중복을 제거한 수만 담을 벡터

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, num;

    cin >> n;

    for(int i=0;i<n;i++) {
        cin >> arr[i];
        arr2[i] = arr[i];
    }

    stable_sort(arr2,arr2+n);

    num = arr2[0];
    v.push_back(arr2[0]);

    for(int i=1;i<n;i++) {
        if(num == arr2[i]) continue; // i-1항과 i항이 같을 경우 == 중복
        v.push_back(arr2[i]);
        num = arr2[i];
    }

    for(int i=0;i<n;i++) {
        // 벡터 v 값 범위 중에 arr[i]보다 작은 수의 개수 출력
        cout << lower_bound(v.begin(),v.end(),arr[i]) - v.begin() << ' ';
    }
}