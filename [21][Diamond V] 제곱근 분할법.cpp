#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> v, u;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M, K; cin >> N >> M >> K;
    M += K;

    v.resize(N);
    for(int i=0; i<N; i++) cin >> v[i];

    int S = sqrt(N); u.resize(N/S + 1);
    for(int i=0; i<N; i++) u[i/S] += v[i];

    while(M--) {
        int Q; cin >> Q;

        if(Q == 1) {
            int idx, val; cin >> idx >> val;
            idx--;

            v[idx] = val;

            u[idx/S] = 0;
            int l = (idx / S) * S, r = l + S;
            for(int i=l; i<r; i++) u[idx/S] += v[i];
        }
        else if(Q == 2) {
            int l, r; cin >> l >> r;
            l--, r--;

            int sum = 0;

            while(l % S != 0 && l <= r) sum += v[l++];
            while((r + 1) % S != 0 && l <= r) sum += v[r--];

            while(l <= r) {
                sum += u[l/S];
                l += S;
            }

            cout << sum << "\n";
        }
    }
}
