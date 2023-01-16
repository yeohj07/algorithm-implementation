#include <bits/stdc++.h>
#define int long long
using namespace std;

struct MF {
    int sz, sour, sink;
    vector<vector<int>> adj, cap, flo;
    vector<int> lv, idx;

    void init(int sz_) {
        sz = sz_;

        adj.resize(sz);
        cap.resize(sz, vector<int>(sz));
        flo.resize(sz, vector<int>(sz));

        lv.resize(sz), idx.resize(sz);
    }

    void edge(int a, int b, int c) {
        adj[a].push_back(b);
        adj[b].push_back(a);
        cap[a][b] = c;
    }

    bool bfs() {
        lv.clear(); lv.resize(sz, -1); lv[sour] = 0;

        queue<int> q; q.push(sour);

        while(!q.empty()) {
            int x = q.front(); q.pop();

            for(auto y : adj[x]) {
                if(lv[y] != -1 || cap[x][y] - flo[x][y] == 0) continue;

                lv[y] = lv[x] + 1;
                q.push(y);
            }
        }

        if(lv[sink] != -1) return true;
        else return false;
    }

    int dfs(int x, int tot) {
        if(x == sink) return tot;

        for(int &i=idx[x]; i<adj[x].size(); i++) {
            int y = adj[x][i];

            if(lv[y] != lv[x] + 1 || cap[x][y] - flo[x][y] == 0) continue;

            int sfl = dfs(y, min(tot, cap[x][y] - flo[x][y]));

            if(sfl == 0) continue;

            flo[x][y] += sfl;
            flo[y][x] -= sfl;

            return sfl;
        }

        return 0;
    }

    int mf(int sour_, int sink_) {
        sour = sour_, sink = sink_;

        int mxf = 0;

        while(bfs()) {
            idx.clear(); idx.resize(sz);

            while(true) {
                int flo = dfs(sour, INT_MAX);

                if(flo == 0) break;

                mxf += flo;
            }
        }

        return mxf;
    }
};

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M, K; cin >> N >> M >> K;

    MF f; f.init(N+M+4);

    int sour = N+M+1, sink = N+M+2, ext = N+M+3;

    f.edge(sour, ext, K);

    for(int i=1; i<=N; i++) {
        f.edge(sour, i, 1);
        f.edge(ext, i, 1);

        int L; cin >> L;

        while(L--) {
            int x; cin >> x;

            f.edge(i, N+x, 1);
        }
    }

    for(int i=1; i<=M; i++) f.edge(N+i, sink, 1);

    cout << f.mf(sour, sink) << "\n";
}
