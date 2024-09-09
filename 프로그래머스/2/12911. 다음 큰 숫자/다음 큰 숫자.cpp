#include <string>
#include <vector>

using namespace std;

int binary(int n) { // n의 2진수에서 1의 개수를 반환
    int count = 0;
    while(n!=1) {
        if(n%2 == 1) count++;
        n = n/2;
    }
    count++;
    return count;
}

int solution(int n) {
    int answer = n;
    int n_count, ans_count;
    bool find = false;
    
    n_count = binary(n); // n의 2진수에서 1의 개수 계산
    
    while(!find) {
        answer += 1;  // 다음 수로 이동
        ans_count = binary(answer);  // 해당 수의 2진수에서 1의 개수 계산
        if(n_count == ans_count) find = true;  // 1의 개수가 같으면 종료  
    }
    return answer;
}