#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool vis[3002];

int solution(int n) {
    int answer = 0;
    if(n == 0 || n == 1) answer = n;
    else {
        for(int i=1;i*i<=n;i++) {
            if(n % i == 0 && !vis[i]) {
                if(n/i == i) answer += i;
                else answer += (i + (n/i));
                vis[i] = true;
                vis[n/i] = true;
            }
        }
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    cout << solution(n);
}