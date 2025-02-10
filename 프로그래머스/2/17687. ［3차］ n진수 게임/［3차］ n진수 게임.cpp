#include <string>
#include <vector>

using namespace std;

char arr[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

string solution(int n, int t, int m, int p) { // 진법: n, 개수: t, 인원: m, 순서: p
    string answer = "";
    int len = t;
    int part = m;
    int ord = p;
    
    //현재 순서와 수
    int now = 1;
    int num = 0;

    while(true){
        int tmp = num;
        string str = "";

        //n진수 변환
        while(true){ // 역순으로 저장
            str += arr[tmp%n]; // 나머지에 변환하여 추가
            tmp = tmp/n; // 몫 갱신

            if(tmp == 0) break;
        }

        //튜브의 순서에 오면 추가
        for(int i = str.length()-1; i>=0; i--){ //  역순으로 넣어야 함
            if(now % part == ord || // 현재 순서(now)가 해당 차례(ord)일 경우 또는
               (part == ord && now % part == 0)) { // 참가자 수(part)와 순서(ord)가 같아 나머지가 0이 되는 경우도 포함
                answer += str[i];
                
                if(answer.length() == len) break;
            }
            now++;
        }

        if(answer.length() == len) break;

        num++;
    }
    return answer;
}