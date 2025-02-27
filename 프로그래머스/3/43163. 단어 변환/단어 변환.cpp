#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

struct Node {
    string word;
    int depth;
};

// 한 개의 알파벳이 차이나는지 확인
bool ch(const string& a, const string& b) {
    int diff = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) diff++;
        if (diff > 1) return false;
    }
    return diff == 1;
}

int solution(string begin, string target, vector<string> words) {
    unordered_set<string> wordSet(words.begin(), words.end());
    
    if (wordSet.find(target) == wordSet.end()) return 0; // target이 없으면 변환 불가

    queue<Node> q;
    q.push({begin, 0});

    while (!q.empty()) {
        Node cur = q.front(); q.pop();
        if (cur.word == target) return cur.depth; // 변환 완료

        for (auto it = wordSet.begin();it != wordSet.end();) {
            if (ch(cur.word, *it)) {
                q.push({*it, cur.depth+1});
                it = wordSet.erase(it);  // 방문한 단어는 제거하여 중복 방문 방지
            } else {
                it++;
            }
        }
    }
    return 0;
}
