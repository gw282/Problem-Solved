#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    vector<char> brace;

    for (char ch : s) {
        if (ch == '(') {
            brace.push_back('(');
        } else if (ch == ')') {
            if (!brace.empty() && brace.back() == '(') {
                brace.pop_back();
            } else {
                return false; // 잘못된 괄호 구조
            }
        }
    }

    // 스택이 비어있으면 올바른 괄호 구조
    return brace.empty();
}
