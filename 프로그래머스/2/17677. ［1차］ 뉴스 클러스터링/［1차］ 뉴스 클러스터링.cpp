#include <string>
#include <unordered_map>
#include <cmath>
using namespace std;

// 문자열을 두 글자씩 끊어서 다중집합을 생성하는 함수
void getElements(string str, unordered_map<string, int>& um) {
    for (auto &c : str) c = tolower(c); // 대소문자 구분 없도록 소문자로 변환
    
    for (int i = 0; i < str.size() - 1; i++) {
        if (isalpha(str[i]) && isalpha(str[i + 1])) { // 알파벳 쌍인지 확인
            um[str.substr(i, 2)]++; // 두 글자씩 끊어서 개수 증가
        }
    }
}

int solution(string str1, string str2) {
    unordered_map<string, int> um1, um2;
    
    getElements(str1, um1); // str1을 다중집합으로 변환
    getElements(str2, um2); // str2를 다중집합으로 변환
    
    int inter_cnt = 0, union_cnt = 0;

    // 교집합 개수 계산
    for (auto &e : um1) {
        if (um2[e.first]) { // str2에도 존재하는 경우
            inter_cnt += min(e.second, um2[e.first]); // 최소값 만큼 교집합 포함
        }
    }

    // 합집합 개수 계산
    for (auto &e : um1) {
        union_cnt += max(e.second, um2[e.first]); // str2에도 있으면 최대값 사용
        um2.erase(e.first); // 중복 계산 방지
    }
    
    for (auto &e : um2) { // 남은 str2의 원소 추가
        union_cnt += e.second;
    }

    return union_cnt == 0 ? 65536 : floor((double)inter_cnt * 65536 / union_cnt);
}
