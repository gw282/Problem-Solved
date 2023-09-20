#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> v1 = {1,2,3,4,5};
    vector<int> v2 = {2,1,2,3,2,4,2,5};
    vector<int> v3 = {3,3,1,1,2,2,4,4,5,5};
    
    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;
    
    for(int i=0;i<answers.size();i++) {
        if(answers[i]==v1[i%5]) {
            cnt1++;
        }
        if(answers[i]==v2[i%8]) {
            cnt2++;
        }
        if(answers[i]==v3[i%10]) {
            cnt3++;
        }
    }
    int mx = max(cnt1,max(cnt2,cnt3));
    
    if(cnt1 == mx) answer.push_back(1);
    if(cnt2 == mx) answer.push_back(2);
    if(cnt3 == mx) answer.push_back(3);
    return answer;
}