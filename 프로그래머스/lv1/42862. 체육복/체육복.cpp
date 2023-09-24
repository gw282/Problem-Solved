#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> l;
    vector<int> r;
    for(int i=0;i<lost.size();i++) {
        if(find(reserve.begin(),reserve.end(),lost[i])!=reserve.end()) continue;
        else l.push_back(lost[i]);
    }   
    for(int i=0;i<reserve.size();i++) {
        if(find(lost.begin(),lost.end(),reserve[i])!=lost.end()) continue;
        else r.push_back(reserve[i]);
    }
    
    answer = n -l.size();
    bool chk[31] = {false,};
    stable_sort(l.begin(),l.end());
    
    for(int i=0;i<l.size();i++) {
        if(find(r.begin(),r.end(),l[i]-1)!=r.end() && chk[l[i]-1] == false) {
            answer++;
            chk[l[i]-1] = true;
        }
        else if(find(r.begin(),r.end(),l[i]+1)!=r.end() && chk[l[i]+1] == false) {
            answer++;
            chk[l[i]+1] = true;
        }
    }
    
    return answer;
}