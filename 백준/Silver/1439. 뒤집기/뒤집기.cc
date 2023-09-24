/*
[2023-09-24 1439 뒤집기]
*/
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int zero = 0, one = 0;
    bool flag = true;

    string s = "";
    cin >> s;

    for(int i=0;i<s.size();i++) {
        flag = true;
        while(s[i] != '1' && i<s.size()) {
            if(flag == true) {
                zero++;
                flag = false;
            }
            ++i;
        }
    }

    for(int i=0;i<s.size();i++) {
        flag = true;
        while(s[i] != '0' && i<s.size()) {
            if(flag == true) {
                one++;
                flag = false;
            }
            ++i;
        }
    }

    cout << min(zero,one);

} 