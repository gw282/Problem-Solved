#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    char x;
    int x_cnt = 0;
    int y_cnt = 0;
    
    for(int i=0;i<s.size();i++) {
        x = s[i];
        x_cnt = 1;
        y_cnt = 0;
        while(x_cnt!=y_cnt) {
            
            if(s[i+1] == x) {
                x_cnt++;
                ++i;
            }
            else if(s[i+1] != x) {
                y_cnt++;
                if(x_cnt==y_cnt) {
                    answer++;
                }
                ++i;
            }
        }
    }
    return answer;
}