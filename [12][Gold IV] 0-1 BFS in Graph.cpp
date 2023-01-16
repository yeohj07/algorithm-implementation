#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, sour, dest; cin >> N >> sour >> dest;

    vector<vector<int>> adj(N+1);
    for(int i=1; i<=N; i++) {
        int M; cin >> M;

        while(M--) {
            int x; cin >> x;

            adj[i].push_back(x);
        }
    }

    deque<int> d; d.push_back(sour);
    vector<int> dis(N+1, INT_MAX); dis[sour] = 0;

    while(!d.empty()) {
        int x = d.front(); d.pop_front();

        if(x == dest) break;

        for(int i=0; i<adj[x].size(); i++) {
            int y = adj[x][i];

            if(dis[y] != INT_MAX) continue;

            if(i == 0) {
                d.push_front(y);
                dis[y] = dis[x];
            }
            else {
                d.push_back(y);
                dis[y] = dis[x] + 1;
            }
        }
    }

    if(dis[dest] != INT_MAX) cout << dis[dest] << "\n";
    else cout << -1 << "\n";
}
