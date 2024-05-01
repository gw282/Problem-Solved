#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    for(int i=0;i<new_id.length();i++) {
        if(new_id[i] >= 65 && new_id[i] <= 90) new_id[i] = new_id[i] + 32;
    }
    
    for(int i=0;i<new_id.length() && answer.size() <=15;i++) {
        if(new_id[i] >= 97 && new_id[i] <= 122) answer+=new_id[i];
        if(new_id[i] >= 48 && new_id[i] <= 57) answer+=new_id[i];
        if(new_id[i] == '-' || new_id[i] == '_') answer+=new_id[i];
        if(new_id[i] == '.') {
            if(answer.size() == 0 || answer.back() == '.') continue;
            else answer+=new_id[i];
        }
    }
    if(answer.empty()) answer += "aaa";
    while(answer.back() == '.' || answer.size() >15) answer.pop_back();
    while(answer.size()<=2) answer += answer.back();
    
    return answer;
}