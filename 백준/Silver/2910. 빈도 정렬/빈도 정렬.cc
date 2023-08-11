/*
[2023-08-11 2910 빈도 정렬]
정렬 방법: 1. 빈도수 -> 2. 먼저 입력된 수
arr배열: 수를 입력받아 정렬한 뒤 각 수의 빈도를 카운팅
vector<pair<int,long long> v: int값에 longlong에 해당되는 수의 횟수를 저장
ord배열: 수를 입력받은 순서를 저장해둔다
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, c;

long long arr[1002];
long long ord[1002];

bool cmp(const pair<int, long long> &a, const pair<int, long long> &b) {
    if(a.first != b.first) return a.first > b.first;
    int a_ord, b_ord;
    for(int i=0;i<n;i++) {
        if(ord[i]==a.second) {
            a_ord = i; break;
        }
    }
    for(int i=0;i<n;i++) {
        if(ord[i]==b.second) {
            b_ord = i; break;
        }
    }
    return a_ord < b_ord;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<pair<int,long long>> v;
    cin >> n >> c;

    for(int i=0;i<n;i++) {
        cin >> arr[i];
        ord[i] = arr[i];
    }
    
    stable_sort(arr,arr+n);

    int cnt = 0;
    for(int i=0;i<n;i++) {
        if(i==0 || arr[i-1]==arr[i]) {
            cnt++;
        }
        else {
            v.push_back(make_pair(cnt,arr[i-1]));
            cnt = 1;
        }
    }
    v.push_back(make_pair(cnt,arr[n-1]));

    stable_sort(v.begin(),v.end(),cmp);

    for(int i=0;i<v.size();i++) {
        for(int j=0;j<v[i].first;j++) {
            cout << v[i].second << ' ';
        }
    }

}