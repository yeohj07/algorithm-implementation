#include <bits/stdc++.h>
#define int long long
using namespace std;

struct s { int a, b, c; };

bool cmp(s x, s y) { return x.c < y.c; }

vector<int> v;

int f(int x) {
    if(v[x] == x) return x;
    else return v[x] = f(v[x]);
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M; cin >> N >> M;

    vector<s> adj(M);

    for(int i=0; i<M; i++)
        cin >> adj[i].a >> adj[i].b >> adj[i].c;

    sort(adj.begin(), adj.end(), cmp);

    v.resize(N+1);
    for(int i=1; i<=N; i++) v[i] = i;

    int ans = 0, cnt = 0;

    for(int i=0; i<adj.size(); i++) {
        int a = adj[i].a, b = adj[i].b, c = adj[i].c;

        if(f(a) == f(b)) continue;

        v[f(a)] = f(b);

        ans += c;
        cnt++;

        if(cnt == N-1) break;
    }

    cout << ans << "\n";
}
