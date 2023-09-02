    /*
    [2023-0902 1654 랜선 자르기]
    st = 0, en = 가장 긴 랜선의 길이로 설정한다
    이분탐색을 통해 mid 값으로 만들 수 있는 랜선 개수 >= n인지 확인한다
    만약 >= 이라면 st = mid+1로 바꾸고 ans 값을 mid로 갱신한다
    만약 < 이라면  en = mid로 바꾼다
    */
    #include <iostream>

    using namespace std;

    int k, n;
    long long cnt;
    int arr[10002];

    int cut() {
        long long st = 1;
        long long en = 0x7fffffff;
        
        while(st < en) {
            long long mid = (st+en+1) / 2;
            cnt = 0;

            for(int i=0;i<k;i++) {
                cnt += arr[i] / mid;
            }
            if(cnt >= n) {
                st = mid;
            }
            else en = mid - 1;
        }
        return st;
    }

    int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin >> k >> n;

        for(int i=0;i<k;i++) {
            cin >> arr[i];
        }
        cout << cut();
    }