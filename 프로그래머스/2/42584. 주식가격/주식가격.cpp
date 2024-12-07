#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(),0);
    stack<int> st;
    
    for(int i=0;i<prices.size();i++) {
        while(!st.empty() && prices[st.top()]>prices[i]){
            answer[st.top()] = i -st.top(); // 현재 인덱스 - 스택에서 꺼낸 인덱스
            st.pop();
        }
        st.push(i);
    }
     while(!st.empty()) {
         // 모든 인덱스에 대해 마지막 가격까지의 일수 계산
        answer[st.top()] = prices.size()-1-st.top();
        st.pop();
    }
    
    return answer;
}