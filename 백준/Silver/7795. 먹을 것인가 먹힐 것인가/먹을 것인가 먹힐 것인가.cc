/*
[2023-09-20 7795 먹을 것인가 먹힐 것인가]
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, a, b, num,cnt;
    vector<int> n;
    vector<int> m;
    cin >> t;

    while(t--) {
        cin >> a >> b;

        cnt = 0;

        for(int i=0;i<a;i++) {
            cin >> num;
            n.push_back(num);
        }
        for(int i=0;i<b;i++) {
            cin >> num;
            m.push_back(num);
        }

        sort(n.begin(),n.end());
        sort(m.begin(),m.end());

        for(int i=0;i<a;i++) {
           cnt += lower_bound(m.begin(),m.end(),n[i]) - m.begin();
        }

        while(!n.empty()) {
            n.pop_back();
        }
        while(!m.empty()) {
            m.pop_back();
        }
        cout << cnt << '\n';
    }
}