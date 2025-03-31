#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

unordered_set<int> primes; // 소수를 저장할 집합
vector<bool> visited; // 방문 여부 체크

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// 백트래킹을 이용하여 숫자를 조합하여 생성
void dfs(string& numbers, string current) {
    if (!current.empty()) {
        int num = stoi(current);
        if (isPrime(num)) {
            primes.insert(num);
        }
    }

    for (int i = 0; i < numbers.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(numbers, current + numbers[i]);
            visited[i] = false;
        }
    }
}

int solution(string numbers) {
    visited.resize(numbers.size(), false);
    dfs(numbers, "");
    return primes.size();
}
