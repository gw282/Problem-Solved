/*
[2023-08-23 4796 캠핑]
*/
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int l,p,v;
    int sum,cnt = 0;

    while(1) {
        cin >> l >> p >> v;

        if(l == 0 && p == 0 && v == 0) {
            return 0;
        }
        sum = 0;

        while(v > p) {
            sum += l;
            v -= p;
        }
        sum += min(l,v);
        cnt += 1;
        cout << "Case " << cnt << ": " << sum <<'\n';
    }
}