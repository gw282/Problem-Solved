#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(int i=0;i<s.size();i++) {
        char c = s[i];
        if(c >='a' && c<='z') {
            if(c+n > 'z') {
                answer += c - 26 + n;
            }
            else answer += c+n;
        }
        else if(c >='A' && c<='Z') {
            if(c+n > 'Z') {
                answer += c - 26 + n;
            }
            else answer += c+n;
        }
        else answer += " ";
    }
    return answer;
}