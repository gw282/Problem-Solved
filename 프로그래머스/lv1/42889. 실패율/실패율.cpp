#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int,double> &a, const pair<int,double> &b) {
    if(a.second != b.second) return a.second > b.second;
    return a.first < b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>> v;
    double cnt, sum;
    
    for(int i=1;i<=N;i++) {
        cnt = 0;
        sum = 0;
        for(int j=0;j<stages.size();j++) {
            if(stages[j]==i) cnt++;
            if(stages[j]>=i) sum++;
        }
        v.push_back(make_pair(i,cnt/sum));
    }
    
    stable_sort(v.begin(),v.end(),cmp);
    
    for(int i=0;i<N;i++) {
        answer.push_back(v[i].first);
    }
    return answer;
}