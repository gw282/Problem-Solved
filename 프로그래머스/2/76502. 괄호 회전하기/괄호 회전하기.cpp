#include <string>
#include <queue>
#include <stack>
#include <map>

using namespace std;

int solution(string s) {
    int answer = 0;
    int size = s.length();
    queue<char> q;
    
    // 문자열을 큐에 삽입
    for (char c : s) {
        q.push(c);
    }
    
    // 괄호 쌍 매핑
    map<char, char> bracket = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };
    
    // 문자열의 각 회전 상태를 검사
    for (int cycle=0; cycle<size; cycle++) {
        stack<char> st; // 여는 괄호를 저장할 스택
        queue<char> copy = q; // 큐를 복사하여 검사
        
        bool isValid = true; // 현재 회전 상태가 유효한지 여부
        
        // 복사한 큐에서 문자를 꺼내면서 괄호 검사를 수행
        while (!copy.empty()) {
            char c = copy.front();
            copy.pop();
            
            // 여는 괄호는 스택에 푸시
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } 
            // 닫는 괄호일 경우
            else if (c == ')' || c == ']' || c == '}') {
                // 스택이 비었거나 짝이 맞지 않으면 false
                if (st.empty() || st.top() != bracket[c]) {
                    isValid = false;
                    break;
                }
                // 짝이 맞으면 여는 괄호 스택에서 제거
                st.pop();
            }
        }

        if (isValid && st.empty()) {
            answer++;
        }

        // 큐를 한 칸 회전
        q.push(q.front());
        q.pop();
    }
    
    return answer;
}
