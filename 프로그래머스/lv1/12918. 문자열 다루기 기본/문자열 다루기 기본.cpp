#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    if(s.size() != 4 && s.size() != 6) {
        answer = false;
        return answer;
    }
    for(int i=0;i<s.size();i++) {
        if(s[i] <= '9' && s[i] >= '0') continue;
        answer = false;
    }
    return answer;
}