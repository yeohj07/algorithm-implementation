#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;

    int dp[10001] = {1, 1};

    for(int i=2; i<=N; i++)
        for(int j=0; j<i; j++) dp[i] = (dp[i] + dp[j] * dp[i-1-j]) % (int)(1e9 + 7);

    cout << dp[N] << "\n";
}
