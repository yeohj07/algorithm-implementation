#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M; cin >> N >> M;

    vector<vector<double>> v(N, vector<double>(M));

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++) cin >> v[i][j];

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            double d = v[i][i], c = v[j][i] / v[i][i];

            for(int k=0; k<M; k++) {
                if(j == i) v[j][k] /= d;
                else v[j][k] -= c * v[i][k];
            }
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) cout << v[i][j] << " ";
        cout << "\n";
    }
}
