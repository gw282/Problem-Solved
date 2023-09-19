#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    
    int day = 0;
    vector<int> v = {31,29,31,30,31,30,31,31,30,31,30,31};
    vector<string> d = {"FRI","SAT","SUN","MON","TUE","WED","THU"};
    for(int i=0;i<a-1;i++) {
        day += v[i];
    }
    day = day + b -1;
    
    answer += d[day%7]; 
    return answer;
}