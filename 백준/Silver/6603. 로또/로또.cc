/*
[2023-08-04 6003 로또]
base condition : 6개를 모두 선택된 경우 출력
recursion : 사용되지 않은 수를 순차적으로 배열에 입력(단 오름차순을 고려함), 사용됐다면 pass
*/
#include <iostream>

using namespace std;

int arr[15];
int num[15];
bool isused[15];

int k;

void func(int cnt) {
    if(cnt==6) { // 6개의 숫자가 모두 선택된 경우
        for(int i=0;i<6;i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=1;i<=k;i++) {
        if(!isused[i]) { // 해당 숫자가 선택되지 않은 경우
            if(cnt==0 || arr[cnt-1]<num[i]) { // cnt가 첫입력이거나, 이전항이 현재항보다 큰 경우(오름차순)
                arr[cnt]=num[i];
                isused[i]=1;
                func(cnt+1);
                isused[i]=0;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1) {
        cin >> k;

        if(k==0) return 0; // 0이 입력되면 종료
        for(int i=1;i<=k;i++) { // k만큼 수를 입력받음
            cin >> num[i];
        }
        func(0);
        cout << '\n';
    }
}