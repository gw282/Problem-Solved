#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer{100,100,-100,-100};

    const int n = wallpaper.size();
    const int m = wallpaper[0].size();


    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(wallpaper[i][j] == '#')
            {
                answer[0] = min(answer[0],i);
                answer[1] = min(answer[1],j);
                answer[2] = max(answer[2],i+1);
                answer[3] = max(answer[3],j+1);
            }
        }
    }

    return answer;
}
