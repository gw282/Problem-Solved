#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    
    unordered_map<string,int> dic;

    int idx = 0;
    string w = "";
    string c = "";
    
    for(int i=1;i<=26;i++) {
        char temp = 'A' + i - 1;
        dic[string(1, temp)] = i;
    }
    
    while(idx < msg.size()) {
        c = msg[idx];
        if(dic.find(w+c) != dic.end()) { // 찾았어요
            w = w + c; // 가장 긴 문자열 계속해서 찾기
        } else { // 못찾았어요
            answer.push_back(dic.find(w)->second); // 색인 번호 추가(출력)
            string temp = w + c;
            dic[temp] = dic.size() + 1; // 사전 추가
            w = c;
        }
        idx++;
    }
    
    if (!w.empty()) {
        answer.push_back(dic.find(w)->second); // 남은 단어 색인 추가
    }
    
    return answer;
}