#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> v;

int f(int x) {
    if(v[x] == x) return x;
    else return v[x] = f(v[x]);
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M; cin >> N >> M;

    v.resize(N+1);
    for(int i=1; i<=N; i++) v[i] = i;

    while(M--) {
        int Q, a, b; cin >> Q >> a >> b;

        if(Q == 0) {
            if(f(a) != f(b)) v[f(a)] = f(b);
        }
        else if(Q == 1) {
            if(f(a) == f(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
