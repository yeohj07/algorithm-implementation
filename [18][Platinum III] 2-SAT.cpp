#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> adj, scc;
vector<int> nnum, cnum;
int ncnt = 0, ccnt = 0;

stack<int> s;
vector<bool> ch;

int y(int x) {
    if(x < 0) return (-x)*2 - 2;
    else return x*2 - 1;
}

int n(int x) {
    x = y(x);

    if(x % 2 == 0) return x + 1;
    else return x - 1;
}

int dfs(int x) {
    nnum[x] = ++ncnt;
    s.push(x);

    int tmp = nnum[x];

    for(int i=0; i<adj[x].size(); i++) {
        int y = adj[x][i];

        if(nnum[y] == 0) tmp = min(tmp, dfs(y));
        else if(!ch[y]) tmp = min(tmp, nnum[y]);
    }

    if(tmp == nnum[x]) {
        vector<int> v;
        ccnt++;

        while(true) {
            int y = s.top();
            s.pop();

            v.push_back(y);

            ch[y] = true;
            cnum[y] = ccnt;

            if(y == x) break;
        }

        sort(v.begin(), v.end());

        scc.push_back(v);
    }

    return tmp;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;

    while(T--) {
        int N, M; cin >> N >> M;

        adj.clear(); adj.resize(N*2);

        while(M--) {
            int a, b; cin >> a >> b;

            adj[n(a)].push_back(y(b));
            adj[n(b)].push_back(y(a));
        }

        nnum.clear(); nnum.resize(N*2);
        cnum.clear(); cnum.resize(N*2);
        ch.clear();   ch.resize(N*2);

        scc.clear();
        ncnt = ccnt = 0;

        for(int i=0; i<N*2; i++)
            if(nnum[i] == 0) dfs(i);

        bool check = true;

        for(int i=0; i<N; i++) {
            if(cnum[i*2] == cnum[i*2 + 1]) {
                check = false;
                break;
            }
        }

        if(check) cout << 1 << "\n";
        else {
            cout << 0 << "\n";
            return 0;
        }

        vector<pair<int, int>> p(N*2);
        for(int i=0; i<N*2; i++) p[i] = {cnum[i], i};

        sort(p.begin(), p.end(), greater<pair<int, int>>());

        vector<int> tf(N*2, -1);

        for(int i=0; i<N*2; i++) {
            int x = p[i].second;

            if(tf[x/2] == -1) {
                if(x % 2 == 1) tf[x/2] = 0;
                else tf[x/2] = 1;
            }
        }

        for(int i=0; i<N; i++) cout << tf[i] << " ";
        cout << "\n";
    }
}
