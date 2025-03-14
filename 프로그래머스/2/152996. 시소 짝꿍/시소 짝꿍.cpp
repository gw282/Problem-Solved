#include <string>
#include <iostream>
#include <vector>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;

    vector<long long> v(1001,0);
    for(int i=0; i<weights.size(); i++) v[weights[i]]++;
    
    for(int i=0; i<weights.size(); i++) {
        //2:3
        if(weights[i]%2==0) {
            long long base = (weights[i]/2) * 3;
            if(base <= 1000) answer+=v[base];
        }
        //3:4
        if(weights[i]%3==0) {
            long long base = (weights[i]/3) * 4;
            if(base <= 1000) answer+=v[base];
        }
        //1:2
        long long base = weights[i] * 2;
        if(base <= 1000) answer+=v[base];
    }
    
    for(int i=100; i<=1000; i++) {
        if(v[i] >= 2) answer += (long long)(v[i] * (v[i]-1))/2;
    }
    
    return answer;
}