#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    stack<char> st;

    for (char c : s) {
        if (!st.empty() && st.top() == c) {
            // 스택의 최상단 문자와 동일하면 제거
            st.pop();
        } else {
            // 아니면 스택에 추가
            st.push(c);
        }
    }

    // 스택이 비어 있으면 1 반환
    return st.empty() ? 1 : 0;
}
