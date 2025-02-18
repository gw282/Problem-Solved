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
    
    map<int, vector<int>> rec;
    
    for (int i = 0; i < records.size(); i++) {
        int time, num;
        string record = records[i];
        time = stoi(record.substr(0, 2)) * 60 + stoi(record.substr(3, 2));
        num = stoi(record.substr(6, 4));
        
        rec[num].push_back(time);
    }
    
    for (const auto& ord : rec) {
        int sum = 0, fee = 0;
        
        int num = ord.first;
        vector<int> times = ord.second;
        
        // 마지막 출차 시간 처리
        if (times.size() % 2 == 1) {
            sum += 1439 - times[times.size() - 1];  // 자정까지 남은 시간
        }
        
        // 입차와 출차 시간의 차이 계산
        for (int i = 0; i < times.size() / 2; i++) {
            sum += times[i * 2 + 1] - times[i * 2];
        }
        
        // 기본 시간보다 더 오래 주차한 경우 요금 계산
        int extra_time = sum - standard_time;
        int time_cnt = (extra_time > 0) ? (extra_time + unit_time - 1) / unit_time : 0;
        
        fee = standard_fee + time_cnt * unit_fee;
        
        answer.push_back(fee);
    }
    
    return answer;
}
