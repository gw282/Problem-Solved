#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    for(int i=0;i<s.size();i++) {
        int cnt = index;
        char c = s[i];
        
        while(cnt) {
            if(c=='z') c -=26;
            if(skip.find(c+1)!= string::npos) {++c;
                                             cout << c <<' ';}
            else {
                ++c;
                cnt--;
            }
            if(c>'z') c = c-26;
        }
        answer += c;
    }
    return answer;
}