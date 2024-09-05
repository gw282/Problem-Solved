#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    // 선물 주고받기 횟수를 기록하는 맵
    unordered_map<string, unordered_map<string, int>> count;
    //선물 지수를 기록하는 맵
    unordered_map<string, int> balance;
    
    // 참가자 초기화
    for (const string& friendName : friends) {
        balance[friendName] = 0;
        for (const string& otherFriend : friends) {
            count[friendName][otherFriend] = 0;
        }
    }

    // 선물 주고받은 횟수 저장
    for(const string& gift : gifts) {
        stringstream ss(gift);
        string sender, receiver;
        ss >> sender >> receiver;
        
        // 선물 보내는 사람의 balance 증가
        balance[sender]++;
        // 선물 받는 사람의 balance 감소
        balance[receiver]--;
        
        // 선물 주고받기 매트릭스 업데이트
        count[sender][receiver]++;
    }

    // 각 친구들이 받을 선물 계산
    for (const string& friendName : friends) {
        int score = 0;

        for (const string& otherFriend : friends) {
            if (friendName != otherFriend) {
                int giftsSent = count[friendName][otherFriend];
                int giftsReceived = count[otherFriend][friendName];
                
                if (giftsSent > giftsReceived) { // 상대방보다 선물 더 많이 줬을 때
                    score++;
                }
                else if(giftsSent == giftsReceived && balance[friendName] > balance[otherFriend]) {
                    // 상대방과 선물 개수가 같지만 선물 지수가 더 클 때
                       score++;
                }
            }
        }
        // 최댓값이면 갱신
        if(score > answer) answer = score;
    }
    
    return answer;
}
