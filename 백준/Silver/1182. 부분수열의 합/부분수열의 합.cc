/*
[2023-08-03 15654 부분수열의 합]
base condition : n개의 수를 확인한 후 합이 s가 되면 cnt++, 아니면 skip
recursion : 분할 정복을 위해 해당 상황에서 cur 수를 포함/미포함한 경우로 나뉘어 재귀호출
*/
#include <iostream>

using namespace std;

int arr[22];

int n,s;
int cnt=0;

void func(int cur, int tot) {
    if(cur==n) { // n개의 수 모두 거쳤을 때(포함 유무 상관없이)
        if(tot==s) cnt++;
        return;
    }
    func(cur+1, tot); // cur에 해당하는 정수는 포함하지 않음
    func(cur+1, tot+arr[cur]); // cur에 해당하는 정수 포함
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> s;
    
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    func(0,0);
    if(s==0) cnt--; // 공집합인 경우를 제외(크기가 양수인 부분수열)

    cout << cnt;
}   