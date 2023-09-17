#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    string s;
    
    for(int i=0;i<t.size()-p.size()+1;i++) {
        s = "";
        for(int j=i;j<i+p.size();j++) {
            s += t[j];
        }
        
        if(stoll(s) <= stoll(p)) answer++;
    }
    return answer;
}