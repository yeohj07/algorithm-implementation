#include <bits/stdc++.h>
#define int long long
using namespace std;

struct MF {
    struct se {
        int num, cap; se *oth;
        se(int num, int cap) : num(num), cap(cap) {}
    };
    vector<vector<se *>> adj;

    void edge(int a, int b, int cap) {
        se *fow = new se(b, cap);
        se *rev = new se(a, 0);

        fow->oth = rev;
        rev->oth = fow;

        adj[a].push_back(fow);
        adj[b].push_back(rev);
    }

    int sz, sour, sink;
    vector<int> lv, idx;

    void init(int sz_) { sz = sz_; adj.resize(sz); }

    bool bfs() {
        lv.clear(); lv.resize(sz, -1); lv[sour] = 0;

        queue<int> q; q.push(sour);

        while(!q.empty()) {
            int x = q.front(); q.pop();

            for(int i=0; i<adj[x].size(); i++) {
                int y = adj[x][i]->num;

                if(lv[y] != -1 || adj[x][i]->cap == 0) continue;

                lv[y] = lv[x] + 1;
                q.push(y);
            }
        }

        if(lv[sink] != -1) return true;
        else return false;
    }

    int dfs(int x, int flo) {
        if(x == sink) return flo;

        for(int &i=idx[x]; i<adj[x].size(); i++) {
            int y = adj[x][i]->num, cap = adj[x][i]->cap;

            if(lv[x] + 1 != lv[y] || cap == 0) continue;

            int sfl = dfs(y, min(flo, cap));

            if(sfl == 0) continue;

            adj[x][i]->cap -= sfl;
            adj[x][i]->oth->cap += sfl;

            return sfl;
        }

        return 0;
    }

    int mf(int sour_, int sink_) {
        int maxf = 0; sour = sour_, sink = sink_;

        while(bfs()) {
            idx.clear(); idx.resize(sz);

            while(true) {
                int sfl = dfs(sour, INT_MAX);

                if(sfl == 0) break;

                maxf += sfl;
            }
        }

        return maxf;
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
