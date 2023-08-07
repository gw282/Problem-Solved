/*
[2023-08-07 2751 수 정렬하기 2]
merge sort 시간복잡도: nlogn
*/
#include <iostream>

using namespace std;

int arr[1000001];
int tmp[1000001];

void merge(int st, int en) {
    int mid = (st+en)/2;
    int left = st;
    int right = mid;

    for(int i=st;i<en;i++) {
        if(right == en) tmp[i] = arr[left++]; // 우측배열이 모두 temp배열에 입력됐을 때 좌측배열 수 삽입
        else if(left == mid) tmp[i] = arr[right++]; // 위의 상황과 반대
        else if(arr[left] <= arr[right]) tmp[i] = arr[left++]; // 우측보다 좌측이 크거나 같으면 좌측 삽입
        else tmp[i] = arr[right++]; // 위의 상황과 반대
    }
    for(int i=st;i<en;i++) {
        arr[i] = tmp[i];
    }
}

void merge_sort(int st, int en) {
    if(st+1 == en) return;
    int mid = (st+en)/2;
    merge_sort(st,mid);
    merge_sort(mid,en);
    merge(st,en);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    merge_sort(0,n);

    for(int i=0;i<n;i++) {
        cout << arr[i] << '\n';
    }
}