/*
[2023-08-28 10815 숫자 카드]
*/
#include <iostream>
#include <algorithm> // binary search

int n,m,num;
int arr[500002];

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    stable_sort(arr,arr+n);

    cin >> m;

    while(m--) {
        cin >> num;

        cout << binary_search(arr,arr+n,num) << ' ';
    }
}