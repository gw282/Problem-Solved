#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    string summary;
    
    for(int i=0;i<skill_trees.size();i++) {
        summary = "";
        for(char c : skill_trees[i]) {
            if(skill.find(c) != string::npos) {
                summary += c;
            }
        }
        if(skill.find(summary) == 0) answer++;
        cout << summary << '\n';
    }
    return answer;
}