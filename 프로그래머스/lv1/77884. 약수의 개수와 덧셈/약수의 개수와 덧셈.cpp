#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int left, int right) {
    int answer = 0;
    for(int j=left;j<=right;j++) {
        for(int i=1;i<32;i++) {
            if(i*i == j) answer -= j * 2;
        }
    }
    for(int i=left;i<=right;i++) {
        answer += i;
    }
    
    return answer;
}