/*
[2023-08-19 2108 통계학]
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int n, mx, num;
double total;

int arr[500002];
int most[8002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    vector<int> v;

    for(int i=0;i<n;i++) {
        cin >> arr[i];
        total += arr[i];
        most[arr[i]+4000]++;
    }

    stable_sort(arr,arr+n);

    cout << floor((total / n) + 0.5) << '\n';
    cout << arr[n/2] << '\n';

    mx = -1;
    for(int i=0;i<8001;i++) {
        if(mx < most[i]) {
            mx = most[i];
            while(!v.empty()) {
                v.pop_back();
            }
            v.push_back(i);
        }
        else if(mx == most[i]) {
            v.push_back(i);
        }
    }
    v.push_back(v[0]);
    cout << v[1] - 4000 << '\n';
    cout << arr[n-1] - arr[0];

}