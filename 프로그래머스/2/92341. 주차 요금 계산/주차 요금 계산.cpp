#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    int standard_time = fees[0];
    int standard_fee = fees[1];
    int unit_time = fees[2];
    int unit_fee = fees[3];
    int time_cnt;
    
    map<int, vector<int>> rec;
    
    for(int i=0;i<records.size();i++) {
        int time, num;
        string record = records[i];
        time = stoi(record.substr(0,2)) * 60 + stoi(record.substr(3,2));
        num = stoi(record.substr(6,4));
        
        rec[num].push_back(time);
    }
    
    for (const auto& ord : rec) {
        int sum = 0, fee = 0;
        
        int num = ord.first;
        vector<int> times = ord.second;
        
        if(times.size() % 2 == 1) {
            sum = sum + 1439 -times[times.size()-1];
        }
        for(int i=0;i<times.size()/2;i++) {
            sum = sum + times[i*2+1] - times[i*2];
        }
        if(sum - standard_time <= 0) time_cnt = 0;
        else if((sum - standard_time) % unit_time != 0) {
            time_cnt = (sum - standard_time) / unit_time + 1;
        } else {
            time_cnt = (sum - standard_time) / unit_time;
        }
        fee = standard_fee + time_cnt * unit_fee;
        
        answer.push_back(fee);
        
    }
    return answer;
}