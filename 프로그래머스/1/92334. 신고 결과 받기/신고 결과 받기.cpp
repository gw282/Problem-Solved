#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    // 결과를 저장할 벡터
    vector<int> answer;
    
    size_t size = id_list.size(); // id_list의 크기를 저장
    int initialValue = 0;
    
    // id_list의 크기만큼의 2D 벡터를 생성하고, 모든 요소를 0으로 초기화
    vector<vector<int>> chart(size, vector<int>(size, initialValue));
    
    // 유저별 신고의 수를 저장
    vector<int> count(size, initialValue);
    
    // 유저가 메일받을 수를 저장
    vector<int> alarm(size, initialValue);
    
    // 신고 내역을 처리합니다.
    for(const string& request : report) {
        stringstream ss(request);
        string reporter, reported;
        
        ss >> reporter >> reported;
    
        // 신고자와 신고받은 사람의 위치를 찾기
        auto it1 = find(id_list.begin(), id_list.end(), reporter);
        auto it2 = find(id_list.begin(), id_list.end(), reported);

        // 위치를 인덱스로 변환 (0부터 시작하는 인덱스)
        int index1 = distance(id_list.begin(), it1);
        int index2 = distance(id_list.begin(), it2);
        
        // 신고자를 행으로, 신고받은 사람을 열로 하여 chart 벡터를 업데이트
        chart[index1][index2] = 1;
    }
    
    // 유저가 신고받은 횟수를 계산
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
           if(chart[i][j] == 1) {
               count[j] += 1;
           }
        }
    }
    
    
    // 유저가 받을 정지 메일 개수 계산
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
           if(chart[i][j] == 1 && count[j] >=k) {
               alarm[i] += 1;
           }
        }
    }
    
    answer = alarm;
    return answer;
}
