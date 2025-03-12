#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, string> recommender; // 추천인 정보를 저장
map<string, int> earnings; // 각 판매원의 수익을 저장

void distributeEarnings(string seller, int profit) {
    if (seller == "-") return;
    
    int commission = profit * 0.1; // 10% 추천 수수료
    earnings[seller] += profit - commission; // 본인 몫 추가

    if (commission == 0) return;
    distributeEarnings(recommender[seller], commission); // 추천인에게 분배
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;

    // 추천 관계 설정
    for (int i = 0; i < enroll.size(); i++) {
        recommender[enroll[i]] = referral[i];
    }

    // 판매 수익 분배
    for (int i = 0; i < seller.size(); i++) {
        distributeEarnings(seller[i], amount[i] * 100);
    }
    
    // 최종 수익 정리
    for (int i = 0; i < enroll.size(); i++) {
        answer.push_back(earnings[enroll[i]]);
    }

    return answer;
}
