#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> adj, par, dis;
vector<int> dep;

void fp(int p, int x, int d) {
    if(adj[x].size() == 0) return;

    par[x][0] = p;
    dep[x] = d;

    for(int i=0; i<adj[x].size(); i++) {
        int y = adj[x][i];

        if(y != p) fp(x, y, d+1);
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;

    adj.resize(N+1);

    for(int i=0; i<N-1; i++) {
        int a, b; cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    par.resize(N+1, vector<int>(30));
    dep.resize(N+1);

    fp(0, 1, 0);

    int H = (int)floor(log2(N+1));

    dis.resize(N+1, vector<int>(30));

    for(int i=1; i<=H; i++)
        for(int j=2; j<=N; j++)
            if(par[j][i-1] != 0) {
                par[j][i] = par[par[j][i-1]][i-1];
                dis[j][i] = dis[j][i-1] + dis[par[j][i-1]][i-1];
            }

    int M; cin >> M;

    while(M--) {
        int a, b; cin >> a >> b;

        if(dep[a] != dep[b]) {
            if(dep[a] < dep[b]) swap(a, b);

            int diff = dep[a] - dep[b];

            for(int i=0; diff>0; i++) {
                if(diff % 2 == 1) a = par[a][i];

                diff /= 2;
            }
        }

        if(a != b) {
            for(int i=H; i>=0; i--)
                if(par[a][i] != 0 && par[a][i] != par[b][i]) {
                    a = par[a][i];
                    b = par[b][i];
                }

            a = par[a][0];
        }

        cout << a << "\n";
    }
}
