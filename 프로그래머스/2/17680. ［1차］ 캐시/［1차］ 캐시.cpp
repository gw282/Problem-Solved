#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> q;

    // 캐시 사이즈가 0일 때
    if (cacheSize == 0) {
        answer = cities.size() * 5;
        return answer;
    }

    for (int i = 0; i < cities.size(); i++) {
        string city = cities[i];
        // 도시 이름을 소문자로 변환
        transform(city.begin(), city.end(), city.begin(), ::tolower);

        if (find(q.begin(), q.end(), city) != q.end()) { //cache hit
            auto it = find(q.begin(), q.end(), city);
            q.erase(it);
            q.push_back(city);
            answer += 1;
        } else {  //cache miss
            if (q.size() >= cacheSize) {
            q.pop_front();   
            }
            q.push_back(city);
            answer += 5; 
        }
    }
    return answer;
}
