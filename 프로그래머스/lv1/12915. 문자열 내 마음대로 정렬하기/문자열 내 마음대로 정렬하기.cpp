#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int g;

bool cmp(string a, string b) {
    if(a[g] != b[g]) return a[g] < b[g];
    return a < b;
}
vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    g = n;
    sort(strings.begin(),strings.end(),cmp);
    
    for(int i=0;i<strings.size();i++) {
        answer.push_back(strings[i]);
    }
    return answer;
}