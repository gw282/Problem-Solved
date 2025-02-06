#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq;

    for(auto i : scoville) pq.push(i);
    
    while(pq.top() < K) {
        if(pq.size() < 2) return -1;
        
        int k1 = pq.top();
        pq.pop();
        
        int k2 = pq.top();
        pq.pop();
        
        pq.push(k1 + (k2 * 2));
        answer++;
    }
    
    return answer;
}