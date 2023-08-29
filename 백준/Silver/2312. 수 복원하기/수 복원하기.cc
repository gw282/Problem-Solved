/*
[2023-08-29 2312 수 복원하기]
*/
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n;

    cin >> t;

    while(t--) {
        cin >> n;

        for(int i=2;i*i<=n;i++) { // i는 인수
            int cnt = 0; // 인수가 나온 횟수 카운팅
            while(n%i == 0) {
                cnt++;
                n /= i;
            }
            if(cnt) cout << i << ' ' << cnt << '\n'; // cnt가 0이 아니면 인수와 나온 횟수를 출력
        }
        if(n != 1) cout << n << ' ' << 1 << '\n';
    }
}