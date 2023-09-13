#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int a = x;
    int tmp = 0;
    
    while(a) {
        tmp += a % 10;
        a /= 10;
    }
    if(x % tmp) {
        answer = false;
    }
    return answer;
}