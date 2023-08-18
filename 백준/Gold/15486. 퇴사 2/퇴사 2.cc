/*
[2023-08-18 15486 퇴사 2]
기존에 했던 방식은 이중 for문으로 시간초과가 발생하므로
뒤에서부터 해당날짜에 최댓값을 계산하면 한번의 for문으로 가능
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n, cur;
int t[1500002], p[1500002], mx[1500002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    
    for(int i=1;i<=n;i++) {
        cin >> t[i] >> p[i];
    }

    for(int i=n;i>=1;i--) {
            if((i + t[i] - 1) <= n) { // 해당 상담 선택가능
                mx[i] = max(mx[i+t[i]]+p[i], mx[i+1]); // 해당 상담을 했을 때와 안했을 때 큰걸 선택
            }
            else mx[i] = mx[i+1]; // 상담이 선택불가하므로 i+1의 값을 가져옴
        }

    cout << *max_element(mx,mx+n+2);

}