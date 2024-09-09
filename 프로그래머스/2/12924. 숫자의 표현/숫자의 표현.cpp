#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for(int i=1;i*(i-1)/2<n;i++) {  // i: 연속된 숫자의 개수
      if((n-(i*(i-1)/2))%i == 0) answer++; // 첫 번째 숫자가 자연수인지 확인
    }

    return answer;
}