/*
[2023-08-18 14501 퇴사]
mx[i] : i항부터 시작
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int t[16], p[16], mx[17];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    
    for(int i=1;i<=n;i++) {
        cin >> t[i] >> p[i];
    }

    for(int i=1;i<=n;i++) {
            if((i + t[i] - 1) <= n) {
                for(int j=i+t[i];j<=n+1;j++)
                    mx[j] = max(mx[j], mx[i] + p[i]);
            }
        }
    cout << *max_element(mx,mx+n+2);

}