/*
[2023-09-13 바둑돌 게임]
가우스의 덧셈 활용
*/
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=1;i<500;i++) {
        if(i*(i+1)/2<=n && (i+1)*(i+2)/2>n) {
            if(i % 2 == 1) {
                cout << 0;
            }
            else if(i % 2 == 0) {
                int a = (i+1) * (i+2) /2;
                cout << a - n ;
            }
        }
    }
}