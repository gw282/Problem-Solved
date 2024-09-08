#include <string>
#include <vector>
#include <cctype> // tolower, toupper, isalpha

using namespace std;

string solution(string s) {
    string answer = "";
    
    bool newWord = true; // 새로운 단어의 시작 플래그

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            // 공백인 경우 그대로 추가
            answer += ' ';
            newWord = true; // 새로운 단어가 시작될 수 있는 상태로 설정
        } else {
            if (newWord && isalpha(s[i])) { // 첫 글자를 대문자로 변환
                answer += toupper(s[i]);
            } else { // 나머지 글자는 소문자로 변환
                answer += tolower(s[i]);
            }
            newWord = false; // 단어가 진행 중
        }
    }

    return answer;
}
