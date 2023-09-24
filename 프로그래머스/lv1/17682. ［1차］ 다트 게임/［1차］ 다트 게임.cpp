#include <string>
#include <cmath>
#include <iostream>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int tmp = 0;
    int now = 0;
    string s = dartResult;
    string dart = "";
    
    for(int i=0;i<s.size();i++) {
        if(s[i] >= '0' && s[i] <= '9') {
            dart += s[i];
        }
        if(s[i] == 'S' || s[i] == 'D' || s[i] == 'T') {
            if(s[i] == 'S') {
                now = stoi(dart);
            }
            else if(s[i] == 'D') {
                now = pow(stoi(dart),2);
            }
            else if(s[i] == 'T') {
                now = pow(stoi(dart),3);
            }
            
            if(s[i+1] == '*' || s[i+1] == '#') {
                if(s[i+1] == '*') {
                    tmp *= 2;
                    now *= 2;
                }
                else if(s[i+1] == '#') {
                    now = -now;
                }
                ++i;
            }
            answer+= tmp;
            tmp = now;
            dart = "";
        }
    }
    answer += now;
    return answer;
}