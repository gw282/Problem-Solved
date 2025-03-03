#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string &a, const string &b) {
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> s;
    
    for(int i=0;i<numbers.size();i++) {
        s.push_back(to_string(numbers[i]));
    }
    
    sort(s.begin(),s.end(),compare);
    
    for(int i=0;i<numbers.size();i++) {
        answer += s[i];
    }
    
    if (answer[0] == '0') {
        answer = "0";
    }
    
    
    return answer;
}