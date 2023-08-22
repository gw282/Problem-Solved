/*
[2023-08-22 1026 보물]
하나는 내림차순, 하나는 오름차순으로 정렬한 뒤
같은 i항끼리 곱해준 뒤 합해준다
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n, sum = 0;

int a[52];
int b[52];

bool cmp(const int &a, const int &b) {
    if(a != b) return a > b;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    for(int i=0;i<n;i++) {
        cin >> b[i];
    }

    stable_sort(a,a+n);
    stable_sort(b,b+n,cmp);

    for(int i=0;i<n;i++) {
        sum += a[i] * b[i];
    }

    cout << sum;
}