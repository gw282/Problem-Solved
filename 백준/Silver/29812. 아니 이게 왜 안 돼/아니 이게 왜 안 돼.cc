/*
[2023-09-16 29812]
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long d, m, n, cnt=0, cnt_d=0, cnt_m=0;
    long long h=0, y=0, u=0, mx=0, sum;
    char c;
    string s;
    cin >> n >> s >> d >> m;
    
    for(int i=0;i<n;i++) {
        c = s[i];

        if(c=='H' || c=='Y' || c=='U') {
            if(c=='H') h++;
            else if(c=='Y') y++;
            else if(c=='U') u++;

            if(cnt==1) cnt_d++;
            else if(cnt>1) {
                if(d+m > cnt * d) cnt_d += cnt;
                else {
                    cnt_d++;
                    cnt_m++;
                }
            }
            cnt =0;
        }
        else {
            cnt++;
        }   
    }
    if(d+m > cnt * d) cnt_d += cnt;
    else {
        cnt_d++;
        cnt_m++;
    }

    mx = min(min(h,y),u);
    sum = d * cnt_d + m * cnt_m;
    
    if(sum ==0) cout << "Nalmeok";
    else cout << sum;
    cout <<'\n';
    if(mx ==0) cout << "I love HanYang University";
    else cout << mx;
}