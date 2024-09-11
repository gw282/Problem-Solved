#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int sum = brown + yellow;

    for(int i=3;i<=sum/2;i++) {
        int x = i;
        int y = sum / i;
        if((x-2)*(y-2) == yellow) {
            answer.push_back(y);
            answer.push_back(x);
            break;
        }
    }
    return answer;
}