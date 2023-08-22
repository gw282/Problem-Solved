/*
[2023-08-22 1744 수 묶기]
1. 값을 입력받을 때 0의 유무와 1의 개수를 카운팅
2. 수열을 오름차순으로 정리
3. 음수의 범위와 양수의 범위(1 제외)를 m과 p를 활용해 산출
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n, sum = 0; // sum: 최댓값이 되는 총합
int p, m; // p ~ n : 양수의 범위, 0 ~ m : 음수의 범위
bool flag = false; // 0이 있는지 여부 판단
int a[52];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
// 1. 값을 입력받을 때 0의 유무와 1의 개수를 카운팅
    for(int i=0;i<n;i++) { 
        cin >> a[i];
        if(a[i] == 0) {
            flag  =true; // 수열에 0 존재
        }
        else if(a[i] == 1) {
            sum += 1; // 1의 개수만큼 총합에 더해줌
        }
    }
// 2. 수열을 오름차순으로 정리
    stable_sort(a,a+n);
// 3. . 음수의 범위와 양수의 범위(1 제외)를 m과 p를 활용해 산출
    m = 0; p = n-1;
    for(int i=0;i<n;i++) {
        if(a[i] < 0) {
            m = i+1; // 음수의 범위 : 0 ~ m
        }
        else if(a[i] > 1) {
            p = i-1; // 양수의 범위 : p ~ n
            break; // 양수의 시작 위치를 찾았으므로 break
        }
    }
// 음수의 경우 : 1)음수*음수,2)음수*0,3)음수로 나누어짐
    for(int i=0;i<m;i++) { 
        if(a[i+1] < 0) { // 다음수도 음수이면
            sum += a[i] * a[i+1]; // 현재수 * 다음수
            i++; // 다다음수를 탐색
        } 
        else if(a[i+1] == 0 && flag) { // 실제로 0이 존재하면
            break; // 음수 * 0은 0이므로 스킵
        }
        else sum += a[i]; // 해당 음수를 sum에 더한다
    }
// 양수의 경우 : 1)양수*양수, 2)양수로 나누어짐
    for(int i=n-1;i>p;i--) {
        if(a[i-1] > 1) { // 다음수도 양수이면
            sum += a[i] * a[i-1]; // 현재수 * 다음수
            i--; // 다다음수를 탐색
        }
        else {
            sum += a[i]; // 양수를 더해준다
            break; // 끝이므로 break;
        }
    }
    cout << sum;
}