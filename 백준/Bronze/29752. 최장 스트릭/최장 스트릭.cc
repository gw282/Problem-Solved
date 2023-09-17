/*
[2023-09-16 29752 최장스트릭]
*/
#include <iostream>

using namespace std;

int n, num, cnt = 0, mx = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0;i<n;i++) {
        cin >> num;
        if(num != 0) {
            cnt++;
            mx = max(mx, cnt);
        }
        else if(num == 0) {
            cnt = 0;
        }
    }
    cout << mx;
}