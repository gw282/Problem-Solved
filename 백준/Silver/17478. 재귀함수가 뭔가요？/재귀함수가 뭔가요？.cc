/*
[2023-07-24 17478 재귀함수가 뭔가요?]
최초 실행 문장 / 조건 상관 없이 출력 문장 / 조건 충족 시 출력 문장 / 조건 불충족 시 출력 문장으로 나뉨
출력 횟수에 따라 언더바를 출력해야하므로 따로 함수 생성해서 출력을 편하게 (input: 언더바 개수, 출력 문장)
*/
#include <iostream>

using namespace std;

int n;

void underbar(int under, string str) { // 횟수에 따른 언더바 출력 함수
    for(int i=0;i<under;i++) {
        cout << "____";
    }
    cout << str;
} 

void func(int cnt) {
    underbar(cnt,"\"재귀함수가 뭔가요?\"\n"); // 조건 상관없이 출력
    if(cnt == n) {  // 조건 충족시 출력
        underbar(cnt, "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n");
    }
    else { // 횟수에 따라 추가된 언더바+아랫문장을 출력
        underbar(cnt,"\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n");
        underbar(cnt,"마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n");
        underbar(cnt,"그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n");
        func(cnt+1);
    }
    underbar(cnt, "라고 답변하였지.\n"); // 조건 상관없이 출력
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << '\n'; // 최초 한번 실행
    func(0);
}