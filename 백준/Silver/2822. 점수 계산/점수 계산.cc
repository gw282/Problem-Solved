/*
[2023-09-27 2822]
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector <pair<int,int>> v;
    vector <int> k;
    int num, sum=0;

    for(int i=1;i<=8;i++) {
        cin >> num;
        v.push_back({num,i});
    }
    stable_sort(v.begin(),v.end(),greater<>());

    for(int i=0;i<5;i++) {
        sum += v[i].first;
    }
    cout << sum << '\n';

    for(int i=0;i<5;i++) {
        k.push_back(v[i].second);
    }
    stable_sort(k.begin(),k.end());

    for(int i=0;i<k.size();i++) {
        cout << k[i] << ' ';
    }
}