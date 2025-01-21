#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 0;
vector<char> vowels = {'A','E','I','O','U'};

bool dfs(string cur, const string& target) {
    answer++;
    
    if (cur == target) return true;
    if (cur.size() == 5) return false;

    for (char vowel : vowels) {
        if (dfs(cur + vowel, target)) return true;
    }
    return false;
}

int solution(string word) {
    for (int i = 0; i < vowels.size(); i++) {
        if (dfs(string(1, vowels[i]), word)) {
            return answer;
        }
    }
    return 0;
}
