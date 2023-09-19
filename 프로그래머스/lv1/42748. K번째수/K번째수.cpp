#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> v;
    
    for(int i=0;i<commands.size();i++) {
        int st = commands[i][0]-1;
        int en = commands[i][1]-1;
        int po = commands[i][2]-1;
        
        for(int i=st;i<=en;i++) {
            v.push_back(array[i]);
        }
        sort(v.begin(),v.end());
        answer.push_back(v[po]);
        
        while(!v.empty()) {
            v.pop_back();
        }
    }
    return answer;
}