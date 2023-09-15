#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int n = 0;
    
    for(int i=0;i<s.size();i++) {
        if(s[i] != ' ') {
            if(n%2 == 0) {
                if(s[i] >= 'a' && s[i] <= 'z')
                answer += s[i] - 32;
                else answer += s[i];
            } 
            else if(n%2 == 1) {
                if(s[i] >= 'A' && s[i] <= 'Z')
                answer += s[i] + 32;
                else answer += s[i];
            }
            n++;
        }
        else {
            answer += " "; 
            n = 0;
        }
    }
    return answer;
}