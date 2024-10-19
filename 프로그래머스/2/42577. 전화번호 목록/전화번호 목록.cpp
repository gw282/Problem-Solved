#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, bool> map;
    
    // 해시에 각 전화번호를 key로 저장하고, value는 true로 설정
    for(const string& number : phone_book) {
        map[number] = true;
    }
    
     // 각 전화번호에 대해 접두사를 생성하며 해시에 존재하는지 확인
    for(const string& number : phone_book) {
        string prefix = "";
        
        for(int i=0;i<number.length();i++) {
            prefix += number[i];
            
             // 해시에 존재하고 현재 전화번호와 다르면 접두사 존재
            if(map.find(prefix) != map.end() && prefix != number) {
                return false;
            }
        }
    }
    return answer;
}