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
        if(right == en) tmp[i] = arr[left++];
        else if(left == mid) tmp[i] = arr[right++];
        else if(arr[left] >= arr[right]) tmp[i] = arr[left++]; 
        // 내림차순이므로 왼쪽 것이 크면 해당 수를 tmp배열에 담음
        else tmp[i] = arr[right++];
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