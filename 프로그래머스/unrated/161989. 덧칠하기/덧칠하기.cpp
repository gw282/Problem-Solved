#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    vector<int> v = section;
    
    while(!v.empty()) {
        int a = v.back();
        a = a - m + 1;
        v.pop_back();
        answer++;
        int b = v.back();
        while(!v.empty() && a<=b) {
            v.pop_back();
            b = v.back();
        }
    }
    return answer;
}