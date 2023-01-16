#include <bits/stdc++.h>
#define int long long
using namespace std;

struct s { int b, e, l, r; };

struct Circulation {
    struct se { int num, cap, ord, idx; };
    vector<vector<se>> adj;

    void edge(int a, int b, int c, int d) {
        adj[a].push_back({b, c, adj[b].size(), d});
        adj[b].push_back({a, 0, adj[a].size()-1, -1});
    }

    int sz, sour, sink;
    vector<int> lv, idx;

    void init(int sz_) { sz = sz_; adj.resize(sz); }

    bool bfs() {
        lv.clear(); lv.resize(sz, -1); lv[sour] = 0;

        queue<int> q; q.push(sour);

        while(!q.empty()) {
            int x = q.front(); q.pop();

            for(auto e : adj[x]) {
                int y = e.num, cap = e.cap;

                if(lv[y] != -1 || cap == 0) continue;

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
            int y = adj[x][i].num, cap = adj[x][i].cap;

            if(lv[x] + 1 != lv[y] || cap == 0) continue;

            int sfl = dfs(y, min(flo, cap));

            if(sfl == 0) continue;

            adj[x][i].cap -= sfl;
            adj[y][adj[x][i].ord].cap += sfl;

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

    bool solve(vector<int> &ver, vector<s> &edg, vector<int> &ans) {
        int N = ver.size()-1;

        for(int i=0; i<edg.size(); i++) {
            ver[edg[i].b] += edg[i].l;
            ver[edg[i].e] -= edg[i].l;
        }

        int psum = 0, msum = 0;

        for(int i=1; i<=N; i++) {
            if(ver[i] > 0) psum += ver[i];
            else msum += ver[i];
        }

        if(psum != abs(msum)) return false;

        sour = N+1, sink = N+2;

        for(int i=1; i<=N; i++) {
            if(ver[i] < 0) edge(sour, i, abs(ver[i]), -1);
            else if(ver[i] > 0) edge(i, sink, ver[i], -1);
        }

        for(int i=0; i<edg.size(); i++)
            edge(edg[i].b, edg[i].e, edg[i].r - edg[i].l, i);

        if(mf(sour, sink) != psum) return false;

        for(int i=1; i<=N; i++)
            for(auto e : adj[i])
                if(e.idx != -1) ans[e.idx] = (edg[e.idx].r - edg[e.idx].l) - e.cap;

        for(int i=0; i<edg.size(); i++) ans[i] += edg[i].l;

        return true;
    }
};

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M; cin >> N >> M;

    Circulation c; c.init(N+3);

    vector<int> ver(N+1);
    for(int i=1; i<=N; i++) cin >> ver[i], ver[i] *= -1; // 공급을 받는다 = 공급이 없었다면 원래 demand 값이 음수

    vector<s> edg(M);
    for(int i=0; i<M; i++)
        cin >> edg[i].b >> edg[i].e >> edg[i].l >> edg[i].r;

    vector<int> ans(M);
    if(!c.solve(ver, edg, ans)) {
        cout << -1 << "\n";
        return 0;
    }

    cout << 1 << "\n";
    for(int i=0; i<M; i++) cout << ans[i] << "\n";
}
