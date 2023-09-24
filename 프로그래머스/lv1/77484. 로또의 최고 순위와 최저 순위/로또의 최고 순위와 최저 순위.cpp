#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int low = 0, high = 0;
    
    for(int i=0;i<lottos.size();i++) {
        for(int j=0;j<win_nums.size();j++) {
            if(lottos[i] == win_nums[j]) {
                low++;
                high++;
            }
        }
    }
    
    for(int i=0;i<lottos.size();i++) {
        if(lottos[i] == 0) {
            high++;
        }
    }
    
    if(high >= 2) high = 7 -high;
    else high  = 6;
    answer.push_back(high);
    
    if(low >= 2) low = 7 -low;
    else low  = 6;
    answer.push_back(low);
    return answer;
}