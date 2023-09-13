#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector <int> v;
    
    while(n) {
        v.push_back(n%10);
        n = n/10;
    }
    sort(v.begin(),v.end());
    
    while(!v.empty()) {
        answer = answer * 10 + v.back();
        v.pop_back();
    }
    return answer;
}