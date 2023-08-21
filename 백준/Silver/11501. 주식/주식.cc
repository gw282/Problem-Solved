/*
[2023-08-21 11501 주식]
입력받은 벡터배열 맨 뒤부터 최고주가 mx와 그 날짜 day를 찾는다
처음부터 day까지의 mx-해당일의 주가를 뺀 값을 총합에 더한다
day+1부터 위의 방법을 반복한다
*/
#include <iostream>
#include <vector>

using namespace std;

int t,n,stock,mx,day;
long long sum;        
int st, en;
vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while(t--) {
        cin >> n;
        sum = 0;

        for(int i=0;i<n;i++) {
            cin >> stock;
            v.push_back(stock);
        }
        st = 0; // 시작날짜
        en = v.size()-1; // 끝날짜
        while(st < en) { // 시작이 끝과 같아지면 반복문 탈출
            mx = 0; // 최곳값
            for(int i=en;i>=st;i--) {
                if(mx < v[i]) {
                    mx = v[i];
                    day = i; // 최고주가일 떄의 날짜
                }
            }
            for(int i=st;i<day;i++) {
                sum += mx; // 최고주가 값을 더해주고
                sum -= v[i]; // 해당날짜의 주가를 빼준다
            }
        st = day+1; // 최고주가의 날짜 다음날부터 반복
        }

        while(!v.empty()) {
            v.pop_back();
        }

        cout << sum << '\n';
    }
}