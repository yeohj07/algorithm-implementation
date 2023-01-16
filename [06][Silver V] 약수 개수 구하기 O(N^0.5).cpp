#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;

    int cnt = 0;

    for(int i=1; i<=sqrt(N); i++) {
        if(N % i == 0) {
            if(N / i == i) cnt++;
            else cnt += 2;
        }
    }

    cout << cnt << "\n";
}
