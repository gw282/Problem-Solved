#include <iostream>
#include <string>
#include <set>
using namespace std;

int solution(string dirs) {
    set<pair<pair<int,int>, pair<int,int>>> visited;
    int x = 5, y = 5;
    int dx[128] = {}, dy[128] = {};

    dx['U'] = 0; dy['U'] = 1;
    dx['D'] = 0; dy['D'] = -1;
    dx['L'] = -1; dy['L'] = 0;
    dx['R'] = 1; dy['R'] = 0;

    int answer = 0;

    for(char dir : dirs) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(nx < 0 || nx > 10 || ny < 0 || ny > 10) continue;

        pair<int, int> from = {x, y};
        pair<int, int> to = {nx, ny};

        // 순서 상관 없이 저장
        if(visited.find({from, to}) == visited.end() &&
           visited.find({to, from}) == visited.end()) {
            visited.insert({from, to});
            visited.insert({to, from});
            answer++;
        }

        x = nx;
        y = ny;
    }

    return answer;
}