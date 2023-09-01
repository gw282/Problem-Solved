/*
[2023-09-01 2295 세 수의 합]
*/
#include <iostream>
#include <algorithm> // binary_search, sort
#include <vector>

using namespace std;

int n;
int arr[1002];
vector <int> v; 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    
    stable_sort(arr,arr+n); // 입력받은 배열 sorting

    for(int i=0;i<n;i++) {
        for(int j=i;j<n;j++) {
            v.push_back(arr[i]+arr[j]); // a,b,c 세가지 수 중 두 수(a + b)룰 더한 값을 저장 
        }
    }

    stable_sort(v.begin(),v.end()); // 벡터 배열 sorting

    for(int i=n-1;i>=0;i--) {
        for(int j=n-2;j>=0;j--) { // a+b+c = d 라고 할 때
            if(binary_search(v.begin(),v.end(),arr[i]-arr[j])) { // d - c = a + b (벡터 배열 저장 값)인지 확인 
                cout << arr[i];
                return 0;
            }
        }
    }
}