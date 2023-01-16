#include <bits/stdc++.h>
#define int long long
using namespace std;

int dp[1001][1001] = {};
int mod = (int)(1e4 + 7);

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M; cin >> N >> M;

    for(int i=0; i<=N; i++) dp[i][0] = 1;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++) dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % mod;

    cout << dp[N][M] << "\n";
}
