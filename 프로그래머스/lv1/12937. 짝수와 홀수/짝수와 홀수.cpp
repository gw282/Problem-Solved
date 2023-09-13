#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    string answer = "";
    if(num % 2 == 1 || num % 2 == -1) answer = "Odd";
    else answer = "Even";
    return answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num;
    
    cin >> num; 
    
    cout << solution(num);
}