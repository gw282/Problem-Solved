/*
[2023-09-23 2847 게임을 만든 동준이]
*/
#include <iostream>
#include <vector>

using namespace std;

vector <int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, num, cnt;

    cin >> n;

    for(int i=0;i<n;i++) {
        cin >> num;
        v.push_back(num);
    }

    cnt = 0;

    for(int i=v.size()-2;i>=0;i--) { 
        //마지막 단계부터 i+1보다 i가 크면 i+1보다 1작은 숫자로 만든다
        if(v[i] >= v[i+1]) {
            cnt += v[i] - v[i+1] + 1;
            v[i] -=  v[i] - v[i+1] + 1;
        }
    }
    cout << cnt;

}