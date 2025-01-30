#include <string>
#include <cctype>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

bool isAlphabet(char c) {
    return (c <= 'z' && c >= 'a');
}

int solution(string str1, string str2) {
    int answer = 0;
    int in = 0;
    int un = 0;
    
    // 소문자로 변환
    string s1 = "", s2 = "";
    for(char &c : str1) {
        s1 += tolower(c);
    }
    for(char &c : str2) {
        s2 += tolower(c);
    }
    
    cout << s1 << ' ' << s2 << '\n';

    multiset<string> sub1;
    multiset<string> sub2;
    
    // 부분 문자열을 저장
    for(int i=0;i<s1.length()-1;i++) {
        char c1 = s1[i], c2 = s1[i+1];
        if(isAlphabet(c1) && isAlphabet(c2)) {
            sub1.insert(s1.substr(i,2));
        }
    }
    
    for(int i=0;i<s2.length()-1;i++) {
        char c1 = s2[i], c2 = s2[i+1];
        if(isAlphabet(c1) && isAlphabet(c2)) {
            sub2.insert(s2.substr(i,2));
        }
    }
    
    // 교집합 계산
    for(auto it = sub1.begin(); it != sub1.end();) {
        auto jt = sub2.find(*it);  // sub2에서 해당 원소 찾기
        if(jt != sub2.end()) {  // 찾으면 교집합이므로 삭제
            sub2.erase(jt);  // sub2에서 제거
            it = sub1.erase(it);  // sub1에서 제거
            in++;
        } else {
            it++;  // 교집합이 없으면 그냥 다음 원소로
        }
    }
    
    // 합집합 계산
    un = in + sub1.size() + sub2.size();
    
    if(un == 0) answer = 65536;
    else answer =in * 65536 / un;
    return answer;
}