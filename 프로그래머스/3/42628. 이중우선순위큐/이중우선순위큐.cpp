#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    multiset<int> set;
    int size = operations.size();
    
    for(int i=0;i<size;i++) {
        char com = operations[i][0];
        
        if(com == 'I') {
            string str = operations[i].substr(2,operations[i].size()-2);
            int num = stoi(str);
            set.insert(num);
        } else {
            if(set.empty()) continue;
            if(operations[i][2] == '-') set.erase(set.begin());
            else set.erase(prev(set.end()));
        }
    }
    
    set.empty() ? answer.push_back(0) : answer.push_back(*prev(set.end()));
    set.empty() ? answer.push_back(0) : answer.push_back(*set.begin());

    return answer;
}