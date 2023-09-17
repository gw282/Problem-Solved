#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(vector<int> &number, int sum, int cnt, int second) {
    if(cnt == 3) {
        if(sum == 0) {
            answer += 1;
        }
        return;
    }
    for(int j=second;j<number.size();j++) {
        dfs(number,sum+number[j],cnt+1,j+1);
    }
}

int solution(vector<int> number) {
    
    for(int i=0;i<number.size();i++) {
        dfs(number,number[i],1,i+1);
    }
    return answer;
}