#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int T; T = 1;

    while(T--) {
        int N; cin >> N;

        vector<int> v(N+1);
        for(int i=1; i<=N; i++) cin >> v[i];

        vector<bool> vis(N+1);
        int cycle = 0, per = 1;

        for(int i=1; i<=N; i++) {
            if(vis[i]) continue;

            int cnt = 0, x = i;

            while(!vis[x]) {
                vis[x] = true;

                x = v[x];
                cnt++;
            }

            per = per * cnt / __gcd(per, cnt);
            cycle++;
        }

        cout << cycle << " " << per << "\n";
    }
}
