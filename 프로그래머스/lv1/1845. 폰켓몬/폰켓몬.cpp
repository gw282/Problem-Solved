#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    int take = nums.size();
    unordered_set<int> s;
    for(int i=0;i<nums.size();i++) {
        if(s.size() >= take/2) break;
        s.insert(nums[i]);
    }
    answer = s.size();
    return answer;
}