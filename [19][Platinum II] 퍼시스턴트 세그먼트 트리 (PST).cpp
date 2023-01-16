#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX = 1e5 + 1;

struct node {
    node *l, *r; int x;
    node() { l = r = NULL, x = 0; }
};

node *add(node *cur, int b, int e, int idx, int val) {
    if(cur == NULL) cur = new node();

    if(idx < b || e < idx) return cur;

    if(b == e) {
        node *ret = new node();

        ret->x = cur->x + 1;

        return ret;
    }

    node *ret = new node();

    node *ln = add(cur->l, b, (b+e)/2, idx, val);
    node *rn = add(cur->r, (b+e)/2 + 1, e, idx, val);

    ret->l = ln, ret->r = rn, ret->x = ln->x + rn->x;

    return ret;
}

int sum(node *cur, int b, int e, int l, int r) {
    if(cur == NULL) return 0;

    if(r < b || e < l) return 0;
    if(l <= b && e <= r) return cur->x;

    return sum(cur->l, b, (b+e)/2, l, r) + sum(cur->r, (b+e)/2 + 1, e, l, r);
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int T; cin >> T;

    while(T--) {
        int N, M; cin >> N >> M;

        vector<vector<int>> v(MAX+1);

        for(int i=0; i<N; i++) {
            int x, y; cin >> x >> y;

            v[x+1].push_back(y+1);
        }

        node *u[MAX+1];
        u[0] = new node();

        for(int i=1; i<=MAX; i++) {
            u[i] = new node();

            u[i]->l = u[i-1]->l, u[i]->r = u[i-1]->r, u[i]->x = u[i-1]->x;

            for(int j=0; j<v[i].size(); j++)
                u[i] = add(u[i], 1, MAX, v[i][j], 1);
        }

        int ans = 0;

        while(M--) {
            int a, b, c, d; cin >> a >> b >> c >> d;

            ans += sum(u[b+1], 1, MAX, c+1, d+1)
                   - sum(u[a], 1, MAX, c+1, d+1);
        }

        cout << ans << "\n";
    }
}
