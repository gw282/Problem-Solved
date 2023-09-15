#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int mx1 = 0;
    int mx2 = 0;
    for(int i=0;i<sizes.size();i++) {
        if(sizes[i][0] < sizes[i][1]) {
            swap(sizes[i][0],sizes[i][1]);
        }
    }
    
    for(int i=0;i<sizes.size();i++) {
            mx1 = max(mx1,sizes[i][0]);
            mx2 = max(mx2,sizes[i][1]);
    }
    
    answer = mx1 * mx2;
    return answer;
}