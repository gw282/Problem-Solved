/*
[2023-09-12 25594 HG 음성기호]
#include <string> : find 함수
str.find(찾고 싶은 문자열, 찾기 시작하는 지점) -> 해당 문자열의 시작지점을 return한다
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <pair<char,string>> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    string hg;

    cin >> str;

    v.push_back({'a',"aespa"});
    v.push_back({'b',"baekjoon"});
    v.push_back({'c',"cau"});
    v.push_back({'d',"debug"});
    v.push_back({'e',"edge"});
    v.push_back({'f',"firefox"});
    v.push_back({'g',"golang"});
    v.push_back({'h',"haegang"});
    v.push_back({'i',"iu"});
    v.push_back({'j',"java"});
    v.push_back({'k',"kotlin"});
    v.push_back({'l',"lol"});
    v.push_back({'m',"mips"});
    v.push_back({'n',"null"});
    v.push_back({'o',"os"});
    v.push_back({'p',"python"});
    v.push_back({'q',"query"});
    v.push_back({'r',"roka"});
    v.push_back({'s',"solvedac"});
    v.push_back({'t',"tod"});
    v.push_back({'u',"unix"});
    v.push_back({'v',"virus"});
    v.push_back({'w',"whale"});
    v.push_back({'x',"xcode"});
    v.push_back({'y',"yahoo"});
    v.push_back({'z',"zebra"});

    int st = 0;
    while(st < str.size()) {
        for(int i=0;i<v.size();i++) { // string 처음부터 끌까지 탐색해
            if(v[i].first == str[st]) { // ex) cau...인 경우: 벡터 배열에서 첫글자가 c인 i값을 찾아
                if(str.find(v[i].second, st) == st) { // 만약 해당 문자열이 존재하는 경우
                    hg += v[i].first; // hg에 문자열의 첫문자를 삽입해
                    st = st+v[i].second.size(); // 스타트 지점을 문자열 다음으로 설정해
                    break; // for문 탈출
                }
                else {
                    cout << "ERROR!";
                    return 0;
                }
            }
        }
    }

    cout << "It's HG!" << '\n' << hg;
}