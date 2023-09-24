#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    int num,mx,sum;
    bool flag;
    
    for(int i=0;i<targets.size();i++) {
        sum = 0;
        for(int j=0;j<targets[i].size();j++) {
            num = 0,mx = 0;
            flag = false;
            for(int k=0;k<keymap.size();k++) {
                if(keymap[k].find(targets[i][j]) != string::npos) {
                    num = keymap[k].find(targets[i][j])+1;
                    if(mx == 0) mx = keymap[k].find(targets[i][j])+1;
                    mx = min(mx,num);
                    flag = true;
                }
            }
            if(flag) sum+= mx;
            else {
                sum = 0; break;
            }
        }
        if(sum) answer.push_back(sum);
        else answer.push_back(-1);
    }
    return answer;
}