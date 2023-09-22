    /*
    [2023-09-22 1057 토너먼트]
    */
    #include <iostream>
    #include <vector>

    using namespace std;

    int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        int n, a, b, c;
        int ans = 0;
        vector <int> v1;

        cin >> n >> a >> b;
        if(a > b) {
            c = a;
            a = b;
            b = c;
        }

        for(int i=1;i<=n;i++) {
            v1.push_back(i);
        }

        while(!v1.empty()) {
            ans += 1;
            vector <int> v2;
            
            for(int i=0;i+1<v1.size();i+=2) {
                if(v1[i] == a && v1[i+1] == b) { // 앞이 a, 뒤가 b이면 정답
                    cout << ans;
                    return 0;
                }
                if(v1[i+1] == a || v1[i+1] == b) { // a나 b면 뒤의 값 push
                    v2.push_back(v1[i+1]);
                }
                else v2.push_back(v1[i]); // 아니면 앞의 값 push
            }
            if(v1.size()%2 == 1) { // 부전승
                v2.push_back(v1.back());
            }
            v1 = v2; // v2 벡터값을 v2로 옮김
        }
    }