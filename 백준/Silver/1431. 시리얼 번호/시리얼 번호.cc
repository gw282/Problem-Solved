/*
[2023-08-09 1431 시리얼 번호]
sort와 cmp를 활용
a가 b의 앞에 와야할 때 true, 아니면 false
*/
#include <iostream>
#include <algorithm> // sort
#include <vector>

using namespace std;

bool cmp(const string& a, const string& b) {
    if(a.length() != b.length()) return a.length() < b.length();
    // 1. 길이가 짧은게 앞으로
    int a1 = 0, b1 = 0;
    for (char c : a) {
        if (c >= '0' && c <= '9') {
            a1 += c - '0';
        }
    }
    for (char c : b) {
        if (c >= '0' && c <= '9') {
            b1 += c - '0';
        }
    }
    if (a1 != b1) return a1 < b1;
     // 2. 자릿수 합이 작은게 앞으로
    return a < b; // 3. 사전순으로
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string num;

    cin >> n;
    vector<string> v;

    while(n--) {
        cin >> num;
        v.push_back(num);
    }

    stable_sort(v.begin(),v.end(),cmp);

    for(int i=0;i<v.size();i++) {
        cout << v[i] <<'\n';
    }
}