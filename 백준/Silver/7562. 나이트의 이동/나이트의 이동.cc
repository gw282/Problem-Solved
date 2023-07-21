/* 
[2023-07-21 7562 나이트의 이동]
dist 배열에 이전-다음 위치로 이동횟수를 누적해서 저장
최종위치의 dist 배열을 출력하면 누적 이동횟수가 저장되어 이씅ㅁ
테스트 케이스 시작시 체스판 크기만큼 dist 배열을 -1로 초기화
*/
#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second

int dist[302][302];
int t;

int dx[8] = {-2,-1,1,2,2,1,-1,-2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    int size;   
    pair<int,int> st;
    pair<int,int> end; 

    while(t--) {
        cin >> size;
        cin >> st.X >> st.Y;
        cin >> end.X >> end.Y;

        for(int i=0;i<size;i++) {
            for(int j=0;j<size;j++)
                fill_n(dist[i],size,-1);
        }  

        dist[st.X][st.Y] = 0; //시작 지점을 0으로 초기화
        queue<pair<int,int>> Q;
        Q.push({st.X,st.Y});

        while(!Q.empty()) {
            pair<int,int> cur = Q.front();
            Q.pop();

            for(int dir=0;dir<8;dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx<0 || nx>=size || ny<0 || ny>=size) continue; //범위 벗어난 경우
                if(dist[nx][ny]>=0) continue; //이미 방문지점인 경우
                dist[nx][ny] = dist[cur.X][cur.Y]+1;
                Q.push({nx,ny});
            }
        }

        cout << dist[end.X][end.Y] << '\n';      
    }

    return 0;
}