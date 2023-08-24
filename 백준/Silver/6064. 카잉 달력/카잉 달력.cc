/*
[2023-08-24 6064 카잉 달력]
*/
#include <iostream>

using namespace std;

int gcd(int a, int b) { // 최대공약수
    if(a == 0) return b;
    return gcd(b%a, a);
}

int lcm(int a, int b) { // 최소공배수
    return a / gcd(a, b) * b; // 반드시 최대공약수로 나누고 b를 곱해야 범위를 넘어가지 않음
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    int m,n,x,y;
    bool flag;
    cin >> t;

    while(t--) {
        cin >> m >> n >> x >> y;

        flag = false;
        if(x == m) x = 0;
        if(y == n) y = 0;
        int lc = lcm(m, n);
        
        for(int i=x;i<=lc;i+=m) { // x, x+m, x+2m 순으로 y+n배수와 같은 값이 있는지 탐색
            if(i == 0) continue; // 최소공배수가 0이 되는 것을 방지
            if(i%n == y) {
                cout << i << '\n';
                flag = true;
                break;
            }
        }
        if(!flag) cout << -1 << '\n';
    }
}