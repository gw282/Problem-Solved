#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    int cnt = 0;
    
    while(num != 1) {
        if(cnt >= 500) {
            return -1;
        }
        if(num % 2 == 0) num /= 2;
        else if(num % 2 == 1) num = num * 3 + 1;
        cnt++;
    }
    
    answer = cnt;
    return answer;
}