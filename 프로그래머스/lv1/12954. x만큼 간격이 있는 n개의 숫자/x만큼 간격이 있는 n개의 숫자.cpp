#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    int a = x;
    
    while(n--) {
        answer.push_back(a);
        a += x;
    }
    return answer;
}