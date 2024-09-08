#include <string>
#include <vector>
#include <algorithm> // count

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int zero_count = 0, turn_count = 0; // 제거할 '0'의 개수, 변환 횟수

    while (s != "1") {
        int one_count = 0; // '1'의 개수
        zero_count += count(s.begin(), s.end(), '0'); // '0'의 개수 세기
        one_count += count(s.begin(), s.end(), '1'); // '1'의 개수 세기

        // 문자열을 이진수로 변환
        s.clear(); // 문자열을 초기화
        while (one_count > 0) {
            s += (one_count % 2) ? '1' : '0'; // 이진수로 변환
            one_count /= 2;
        }
        turn_count++; // 변환 횟수 증가
    }

    answer.push_back(turn_count);
    answer.push_back(zero_count);
    
    return answer;
}
