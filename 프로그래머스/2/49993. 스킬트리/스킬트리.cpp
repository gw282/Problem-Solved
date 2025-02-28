#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(int i=0;i<skill_trees.size();i++) {
        string str = "";
        for(auto c : skill_trees[i]) {
            if(skill.find(c) != string::npos) {
                str += c;
            }
        }
        if(skill.find(str) == 0) answer++;
    }
    return answer;
}