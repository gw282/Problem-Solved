#include <queue>
#include <vector>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq(works.begin(), works.end());
    
    while(n-- && !pq.empty()) {
        int top = pq.top();
        pq.pop();
        if(top > 0) {
            pq.push(top - 1);
        } else {
            pq.push(0);
        }
    }
    
    while(!pq.empty()){
        int work = pq.top();
        pq.pop();
        answer += work * work;
    }
    
    return answer;
}
