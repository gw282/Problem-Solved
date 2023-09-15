/*
[2023-09-15 날짜 계산]
그냥 구현
*/
#include <iostream>

using namespace std;

int e, s, m; // 15 28 19
int a, b, c;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt=0;
    int a=0, b=0, c=0;
    cin >> e >> s >> m;
    if(e==1 && s==1 && m==1) {
        cout << 1;
        return 0;
    }
    while(a!=e || b!=s || c!=m) {
        cnt++;
        ++a;
        ++b;
        ++c;
        if(a>15) {
            a -= 15;
        }
        if(b>28) {
            b -= 28;
        }
        if(c>19) {
            c-= 19;
        }
    }
    cout << cnt;    
}