#include <string>
#include <vector>
#include <sstream> //stringstream
#include <algorithm> //sort

using namespace std;

string solution(string s) {
    string answer = "";

    // 숫자 문자열을 저장할 벡터
    vector<int> numbers;

    // 문자열 스트림을 생성하여 입력 문자열을 스트림으로 변환
    stringstream ss(s);
    int number;
    
    // 스트림에서 숫자를 추출하여 벡터에 저장
    while (ss >> number) {
        numbers.push_back(number);
    }

    // 벡터를 오름차순으로 정렬
    sort(numbers.begin(), numbers.end());


    answer += to_string(numbers.front()) + ' ' + to_string(numbers.back());

    return answer;
}
