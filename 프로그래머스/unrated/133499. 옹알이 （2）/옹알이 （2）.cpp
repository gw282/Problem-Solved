#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    for(int i=0;i<babbling.size();i++) {
        string s = "";
        string baby = "";
        bool flag = true;
        
        for(int j=0;j<babbling[i].size();j++) {
            s += babbling[i][j];
            cout << s << ' ';
            if((s == "aya" || s == "ye" || s == "woo" || s == "ma")) {
                if(s == baby) {
                    flag = false;
                    break;
                }
                baby = s;
                s = "";
            }
        }
        if(s.size() == 0 && flag) {
            answer++;
        } 
    }
    return answer;
}