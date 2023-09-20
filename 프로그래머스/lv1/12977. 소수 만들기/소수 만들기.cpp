#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    bool flag = false;
    vector<int> v;
    
    for(int i=0;i<nums.size()-2;i++) {
        for(int j=i+1;j<nums.size()-1;j++) {
            for(int k=j+1;k<nums.size();k++) {
                v.push_back(nums[i]+nums[j]+nums[k]);
            }
        }
    }
    
    for(int i=0;i<v.size();i++) {
        flag = true;
        for(int j=2;j*j<=v[i];j++) {
            if(v[i]%j==0)  {
                flag = false;
                break;
            }
        }
        if(flag) answer++;
    }
    
    return answer;
}