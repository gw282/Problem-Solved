/*
[2023-09-30 1475 방 번호]
*/
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[10] = {0,};
    string s = "";
    int mx = 0;

    cin >> s;

    for(int i=0;i<s.size();i++) {
        if(s[i]=='6' || s[i]=='9') {
            arr[6]++;
        }
        else arr[s[i]-'0']++;
    }

    if(arr[6]%2==0) arr[6] = arr[6]/2;
    else arr[6] = arr[6]/2 + 1;
    for(int i=0;i<10;i++) {
        mx = max(arr[i],mx);
    }

    cout << mx;
}