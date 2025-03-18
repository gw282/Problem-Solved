#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 장르 정렬 함수: 재생 횟수가 많은 순서대로 정렬
bool compareGenres(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second > b.second;
}

// 노래 정렬 함수: 재생 횟수가 많고, 같으면 고유 번호가 작은 순서대로 정렬
bool compareSongs(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map<string, vector<pair<int, int>>> songs; // {장르: [(재생 횟수, 고유 번호)]}
    unordered_map<string, int> playCount; // {장르: 총 재생 횟수}
    
    // 데이터 저장
    for (int i=0;i< genres.size();i++) {
        songs[genres[i]].push_back({plays[i], i});
        playCount[genres[i]] += plays[i];
    }
    
    // 장르별 총 재생 횟수 정렬
    vector<pair<string, int>> sortedGenres(playCount.begin(), playCount.end());
    sort(sortedGenres.begin(), sortedGenres.end(), compareGenres);
    
    vector<int> answer;
    for (auto& genre : sortedGenres) {
        string genreName = genre.first;
        vector<pair<int, int>>& songList = songs[genreName];
        
        // 각 장르 내에서 노래 정렬
        sort(songList.begin(), songList.end(), compareSongs);
        
        // 최대 2곡 선택
        for (size_t j=0; j<songList.size() && j<2;j++) {
            answer.push_back(songList[j].second);
        }
    }
    
    return answer;
}