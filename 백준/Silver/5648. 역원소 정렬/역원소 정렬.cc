/*
[2023-08-09 5648 역원소 정렬]
reverse(str.begin(),str.end()) : 해당 문자열을 반대로 저장
stoll : string to long long (문자열을 정수로)
10^12까지 포함해야하므로 long long 사용
*/
#include <iostream>
#include <algorithm> // sort
#include <string> // stoi
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long rev;
    string str;
    vector<long long> v;

    cin >> n;

    while(n--) {
        cin >> str;
        reverse(str.begin(),str.end());
        rev = stoll(str);
        v.push_back(rev);
    }

    stable_sort(v.begin(),v.end());

    for(int i=0;i<v.size();i++) {
        cout << v[i] <<'\n';
    }
}