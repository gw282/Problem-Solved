/*
[2023-09-05 16953 A → B]
*/
#include <iostream>

using namespace std;

int a, b, cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;

    cnt = 1;

    while(a < b) {
        if(b % 10 == 1) { // 끝자리가 1
            b = b/10;
            cnt++;
        }
        else if(b % 2 == 0) { // 2로 나누어떨어짐
            b = b/2;
            cnt++;
        }
        else {
            cout << -1;
            return 0;
        }
    }
    if(a != b) { // a와 b가 다르다면
        cout << -1;
    }
    else cout << cnt; // 같으면 cnt 출력
}