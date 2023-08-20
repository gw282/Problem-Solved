/*
[2023-08-20 2457 공주님의 정원]
날짜를 소숫점으로 입력받는다 ex) 1월 1일 = 1.01
꽃피는 시작 날짜를 기준으로 하여 오름차순 정렬한다
만약 시작 날짜가 같다면 끝나는 날짜를 기준으로 하여 내림차순으로 정렬한다(큰 의미는 없음)
시작 날짜, 끝날짜 둘 다를 3.01로 설정 -> 시작 날짜가 11.31보다 클 때까지 반복
시작 날짜보다 작으면서 && 끝나는 날짜가 가장 큰 수를 선택 -> 그 후 cnt++
만약 시작 날짜, 끝날짜가 같다? -> 11.31까지 도달 x -> print 0
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<pair<float,float>> v;

bool cmp(const pair<float,float> &v1, const pair<float,float> &v2) {
    if(v1.first != v2.first) return v1.first < v2.first;
    return v1.second > v2.second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int st1, en1;
    float st2, en2;
    int cnt = 0;

    for(int i=0;i<n;i++) {
        cin >> st1 >> st2 >> en1 >> en2;
        st2 = st1 + 0.01 * st2;
        en2 = en1 + 0.01 * en2;
        v.push_back({st2,en2});
    }
    
    stable_sort(v.begin(),v.end(),cmp);

    float pre = 3.01; // 현재 날짜
    float fut; // 다음 날짜
    float fin = 12.01; // 최종 끝 날짜

    while(pre < fin) {
        fut = pre;
        for(int i=0;i<n;i++) {
            if(v[i].first > pre) break; // 현재 날짜보다 뒤인 경우 pass
            if(fut < v[i].second) { // 다음 날짜(낙화 일자)가 더 큰 것이 있을 경우
                fut = v[i].second; // 낙화 일자가 가장 나중인 걸 선택
            }
        }
        if(pre == fut) { // 현재 날짜와 다음 날짜가 같으면 더이상 선택할 게 없다
            cout << 0;
            return 0;
        }
        pre = fut; // 다음 날짜가 현재 날짜가 된다
        cnt++;
    }
    cout << cnt;
}