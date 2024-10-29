#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(vector<int>& numbers, int i, int total, int target) {
    if (i == numbers.size()) {
        if (total == target) {
            answer += 1;
        }
        return;
    }
    
    dfs(numbers, i+1, total+numbers[i], target);
    dfs(numbers, i+1, total-numbers[i], target);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, 0, 0, target);
    return answer;
}
