/*
1차원 배열을 사용하여 수빈-동생까지 가는 시간을 출력
dist 배열에 이전-다음 위치로 이동 시간을 누적해서 저장
동생 위치의 dist 배열을 출력하면 걸린 시간이 저장되어 있음
-배열 초기화 -> fill_n(배열 이름,초기화할 배열 개수(0부터),초기화할 값)
-for(int 변수 : {배열{}) -> 배열 안에 있는 값 처음부터 끝까지 반복문을 돌림
*/
#include <iostream>
#include <queue>
using namespace std;

#define MAX 1000002
int dist[MAX];

int main(void) {
	ios::sync_with_stdio(false);
    cin.tie(0);

    int n,k;
    cin >> n >> k;

    fill_n(dist,MAX,-1); //거리 배열을 -1로 초기화
    // -1: 미방문, 0보다 큰 경우: 방문까지 걸린 시간을 배열에 저장
    dist[n] = 0; // 수빈이 위치 0으로 설정
    queue<int> Q;
    Q.push(n);

    while(dist[k] == -1) { //동생 위치를 가지 못한 경우
        int cur = Q.front();
        Q.pop();

        for(int move : {cur-1, cur+1, cur*2}) { // 수빈이 -1, +1, *2 위치로 이동
            if(move < 0 || move > 100000) continue; //범위 벗어나면 스킵
            if(dist[move] != -1) continue; // 이미 방문한 위치면 스킵

            dist[move] = dist[cur]+1; //이전 방문 위치에서 +1한 값 저장
            Q.push(move); //새롭게 바뀐 방문 위치 push
        }
    }

    cout << dist[k]; //동생 위치까지 걸린 시간 출력
    return 0;
}