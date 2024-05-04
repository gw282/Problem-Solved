#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    // 현재 날짜를 정수로 변환
    int int_today;
    string year_today, month_today, day_today;
    year_today = today.substr(0, 4); // yyyy
    month_today = today.substr(5, 2); // mm
    day_today = today.substr(8, 2); // dd
    int_today = stoi(year_today) * 12 * 28 + stoi(month_today) * 28 + stoi(day_today);
    
    // 개인정보와 조건을 비교하여 결과를 구함
    for(int i = 0; i < privacies.size(); i++) {
        for(int j = 0; j < terms.size(); j++) {
            // 두 문자열의 알파벳 부분이 같은지 비교
            if(privacies[i][11] == terms[j][0]) {
                // 개인정보의 날짜를 정수로 변환
                int int_day;
                string year, month, day, month_terms;
                year = privacies[i].substr(0, 4); // yyyy
                month = privacies[i].substr(5, 2); // mm
                month_terms = terms[j].substr(2); // terms[j]의 2번째 인덱스부터 끝까지 추출
                day = privacies[i].substr(8, 2); // dd
                int_day = stoi(year) * 12 * 28 + stoi(month) * 28 + stoi(month_terms) * 28 + stoi(day);
                
                // 비교하여 결과 추가
                if(int_today >= int_day) answer.push_back(i + 1);
            }
        }
    }
    return answer;
}
