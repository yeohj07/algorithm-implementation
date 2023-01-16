#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M; cin >> N >> M;

    M = min(M, N - M);

    int ans = 1;

    for(int i=1; i<=M; i++) {
        ans *= N;
        ans /= i;

        N--;
    }

    cout << ans << "\n";
}
