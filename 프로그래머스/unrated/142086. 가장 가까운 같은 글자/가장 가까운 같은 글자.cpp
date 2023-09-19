#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    for(int i=0;i<s.size();i++) {
        int cnt = -1;
        char c = s[i];
        
        for(int j=0;j<i;j++) {
            if(c == s[j]) {
                cnt = i - j;
            }
        }
        answer.push_back(cnt);
    }
    return answer;
}