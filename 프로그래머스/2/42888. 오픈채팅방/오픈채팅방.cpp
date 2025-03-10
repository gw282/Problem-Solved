#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;

    int n = record.size();
    vector<string> actionList;
    vector<string> uidList;
    unordered_map<string, string> userMap;

    for (int i=0;i<n;i++) {
        int firstSpace = record[i].find(' ');
        string action = record[i].substr(0, firstSpace); // 첫 단어
        actionList.push_back(action);

        string uid;
        if (action == "Leave") {
            uid = record[i].substr(firstSpace + 1);
        } else {
            int secondSpace = record[i].find(' ', firstSpace + 1);
            uid = record[i].substr(firstSpace + 1, secondSpace - firstSpace - 1); // 두번째 단어
            string nickname = record[i].substr(secondSpace + 1); // 세번째 단어
            userMap[uid] = nickname;
        }
        
        uidList.push_back(uid);
    }

    for (int i=0;i<n;i++) {
        string result = "";
        result += userMap[uidList[i]];
        
        if (actionList[i] == "Enter") result += "님이 들어왔습니다."; 
        else if (actionList[i] == "Leave") result += "님이 나갔습니다."; 
        else if (actionList[i] == "Change") continue; 
        
        answer.push_back(result);
    }
    
    return answer;
}
