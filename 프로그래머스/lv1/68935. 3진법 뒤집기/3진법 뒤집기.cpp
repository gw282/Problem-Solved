#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector <int> v;
    
    int num = n;
    while(num/3) {
        v.push_back(num%3);
        num /= 3;
    }
    
    v.push_back(num);
    
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++) {
        answer += v[i] * pow(3,i);
    }
    return answer;
}