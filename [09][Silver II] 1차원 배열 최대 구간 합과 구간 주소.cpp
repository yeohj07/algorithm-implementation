#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;

    vector<int> v(N);
    for(int i=0; i<N; i++) cin >> v[i];

    int sum = 0, Min = 0, ans = INT_MIN;
    int l = 1, r = 1, ltmp = 1;

    for(int i=0; i<N; i++) {
        sum += v[i];

        if(sum - Min > ans) {
            ans = sum - Min;
            l = ltmp + 1;
            r = i + 1;
        }

        if(sum < Min) {
            Min = sum;
            ltmp = i + 1;
        }
    }

    cout << l << " " << r << " " << ans << "\n";
}
