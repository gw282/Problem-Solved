/*
[2023-08-20 1931 회의실 배정]
끝나는시간이 작은 순 -> 시작시간이 작은 순으로 정렬
끝나는 시간 이후부터 가능한 회의를 계속 입력받는다(정렬을 해뒀기 때문)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int,int>> v;

bool cmp(const pair<int, int> &v1, const pair<int, int> &v2) {
    if(v1.second != v2.second) return v1.second < v2.second;
    return v1.first < v2.first;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0;i<n;i++) {
        int st, en;
        cin >> st >> en;
        v.push_back({st,en});
    }

    stable_sort(v.begin(),v.end(),cmp);

    int cnt = 1; // 초기값 세팅
    int fin = v[0].second;
    for(int i=1;i<n;i++) {
        if(fin <= v[i].first) { // 회의 종료시간보다 다음회의 시작시간이 같거나 더 커야함
            cnt++;
            fin = v[i].second; // 다음회의 종료시간을 fin값으로 변경
        }
    }
    cout << cnt;
}