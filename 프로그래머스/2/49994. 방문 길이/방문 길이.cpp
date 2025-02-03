#include <string>
#include <iostream>
using namespace std;

bool vis[11][11][11][11] = {false,};
int x = 5, y = 5;

bool check(int x, int y) {
    return (x >=0 && x <= 10 && y >= 0 && y<= 10);
}


int solution(string dirs) {
    int answer = 0;
    
    for(int i=0;i<dirs.length();i++) {
        int nx, ny;
        if(dirs[i] == 'U') {
            nx = x; ny = y + 1;
        } else if(dirs[i] == 'D') {
            nx = x; ny = y - 1;
        } else if(dirs[i] == 'R') {
            nx = x + 1; ny = y;
        } else if(dirs[i] == 'L') {
            nx = x - 1; ny = y;
        }
        if(check(nx,ny)) {
            if(dirs[i] == 'U' || dirs[i] == 'D') {
                if(!vis[y][ny][x][x] && !vis[ny][y][x][x]) {
                    vis[y][ny][x][x] = true;
                    vis[ny][y][x][x] = true;
                    answer+=1;
                    //cout << "y: " << x-5 << ' ' << ny-5 << '\n';
                }
                y = ny;
            } else if(dirs[i] == 'L' || dirs[i] == 'R') {
                if(!vis[y][y][x][nx] && !vis[y][y][nx][x]) {
                    vis[y][y][x][nx] = true;
                    vis[y][y][nx][x] = true;
                    answer+=1;
                    //cout << "x: " << nx-5 << ' ' << y-5 << '\n';
                }
                x = nx;
            }
        }
        //cout << "po " << x-5 << ' ' << y-5 << '\n';
    }
    return answer;
}