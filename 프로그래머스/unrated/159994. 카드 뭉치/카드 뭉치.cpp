#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    
    int c1=0, c2=0;
    
    for(int i=0;i<goal.size();i++) {
        if(goal[i] == cards1[c1]) c1++;
        else if(goal[i] == cards2[c2]) c2++;
        else return "No";
    }
    return answer;
}