#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    sort(score.begin(),score.end(),greater<>());
    
    for(int i=m-1;i<score.size();i=i+m) {
        if(score[i] > k) score[i] = k;
        answer += score[i] * m;
    }
    return answer;
}