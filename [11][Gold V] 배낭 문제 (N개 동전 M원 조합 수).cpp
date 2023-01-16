#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;

    vector<int> v(N);
    for(int i=0; i<N; i++) cin >> v[i];

    int M; cin >> M;

    vector<int> dp(M+1); dp[0] = 1;
    for(int i=0; i<N; i++)
        for(int j=v[i]; j<=M; j++) dp[j] += dp[j - v[i]];

    cout << dp[M] << "\n";
}
