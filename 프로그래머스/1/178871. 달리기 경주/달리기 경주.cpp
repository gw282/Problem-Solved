#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    unordered_map<string, int> playerIndexMap;

    // 선수 이름과 인덱스를 해시 맵에 저장
    for (int i = 0; i < players.size(); ++i) {
        playerIndexMap[players[i]] = i;
    }

    // 호출된 선수를 찾아서 위치 교환
    for (string calling : callings) {
        int index = playerIndexMap[calling];
        swap(players[index], players[index - 1]);
        playerIndexMap[players[index]] = index;
        playerIndexMap[players[index - 1]] = index - 1;
    }

    answer = players;
    return answer;
}
