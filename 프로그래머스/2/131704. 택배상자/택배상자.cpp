#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<int> order) {
    stack<int> st;
    int answer = 0;
    
    
    for(int i=1;i<=order.size();i++) {
        st.push(i);
        
        while(!st.empty() && st.top() == order[answer]) {
            answer++;
            st.pop();
        }
    }
    return answer;
}