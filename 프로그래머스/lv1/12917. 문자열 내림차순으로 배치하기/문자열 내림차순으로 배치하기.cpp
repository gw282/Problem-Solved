#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector <int> v;
    
    for(int i=0;i<s.size();i++) {
        v.push_back(s[i]-'0');
    }
    sort(v.begin(),v.end(),greater<>());
    
    for(int i=0;i<s.size();i++) {
        answer += char(v[i] +'0');
    }
    return answer;
}