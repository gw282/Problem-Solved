#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int s = n;
    int r = -1;
    
    while (s!=0) {
        r = s % 3;
        s = s / 3;

        if (r == 0) {
            answer = "4" + answer;
            s--;
        } else if (r == 1) {
            answer = "1" + answer;
        } else if (r == 2) {
            answer = "2" + answer;
        }
    }

    return answer;
}