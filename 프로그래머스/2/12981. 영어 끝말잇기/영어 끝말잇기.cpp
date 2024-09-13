#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    char last = '\0'; 
    for(int i = 0; i < words.size(); i++) {
    
        if(i != 0) {
            // 이전 단어의 마지막 문자로 시작하지 않는 경우
            if(words[i][0] != last) {
                answer.push_back(i%n + 1);
                answer.push_back(i/n + 1);
                return answer;
            }
            // 이미 사용된 단어인 경우
            for(int j = 0; j < i; j++) {
                if(words[j] == words[i]) {
                    answer.push_back(i%n + 1);
                    answer.push_back(i/n + 1);
                    return answer;
                }
            }
        }
        // 단어의 마지막 문자로 갱신
        last = words[i].back();
    }
    
    // 탈락자가 없는 경우
    answer.push_back(0);
    answer.push_back(0);
    return answer;
        
}
