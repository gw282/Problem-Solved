#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    int cnt;
    vector<int> v;
    
    for(int i=1;i<=number;i++) {
        cnt = 0;
        for(int j=1;j*j<=i;j++) {
            if(j*j==i) cnt++;
            else if(i%j==0) cnt+=2;
        }
        v.push_back(cnt);
    }
    
    for(int i=0;i<v.size();i++) {
        if(v[i] > limit) answer += power;
        else answer += v[i];
    }
    return answer;
}