/*
[2023-09-13 10610 30]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string n;
    int sum;
    vector <int> v;

    cin >> n;   

    for(char c : n) {
        v.push_back(c-'0');
    }

    sort(v.begin(),v.end(),greater<int>());
    sum = accumulate(v.begin(),v.end(),0);

    if(v.back() != 0 || sum % 3 != 0) {
        cout << -1;
        return 0;
    }


    for(int i=0;i<v.size();i++) {
        cout << v[i];
    }
}