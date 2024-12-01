#include <iostream>
#include <algorithm>

using namespace std;

int n, num, target;
int arr[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    // 배열 입력
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 타겟값 입력
    cin >> target;

    // 배열을 오름차순으로 정렬
    sort(arr, arr + n);

    int count = 0;
    int left = 0, right = n - 1;

    // 두 포인터 기법 사용
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            count++;
            left++;
            right--;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    cout << count;
}
