#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";  // 결과 문자열
    int idx = -1;  // 가장 큰 수의 인덱스를 추적

    // number에서 k개 숫자를 제거하며 가장 큰 수를 만들기
    for(int i=0;i<number.size()-k;i++) {
        char mx = ' ';  // 현재 구간에서 가장 큰 값

        // 최대값 찾기
        for(int j=idx+1;j<=k+i;j++) {
            if(mx < number[j]) {
                mx = number[j];  
                idx = j;  // 최대값의 인덱스 갱신
            }
        }
        answer += mx;
    }
    
    return answer;
}