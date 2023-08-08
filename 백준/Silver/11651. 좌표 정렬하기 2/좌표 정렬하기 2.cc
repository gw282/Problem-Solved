/*
[2023-08-08 11651  좌표 정렬하기 2]
stable_sort: 기존 순서를 보장해줌 (sort와의 차이점)
make_pair: pair를 만들어주는 함수
ex) pair<int,int> num = make_pair(1,2);
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b) {
    if(a.second != b.second) return a.second < b.second;
    return a.first < b.first; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int i1,i2;
    cin >> n;
    vector<pair<int,int>> v;
    while(n--) {
        cin >> i1 >> i2;
        pair<int,int> info = make_pair(i1,i2);
        v.push_back(info);
    }

    stable_sort(v.begin(), v.end(),cmp);

    for(int i=0;i<v.size();i++) {
        cout << v[i].first << ' ' << v[i].second << '\n';
    }
}