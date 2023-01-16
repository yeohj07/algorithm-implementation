#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef vector<vector<int>> mat;
int mod = 1e9;

mat f(mat& v, mat& u) {
    int N = 2;
    mat w(N, vector<int>(N));

    for(int i=0; i<v.size(); i++)
        for(int j=0; j<u[0].size(); j++)
            for(int k=0; k<v[0].size(); k++)
                w[i][j] = (w[i][j] + v[i][k] * u[k][j]) % mod;

    return w;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;

    mat mul(2, vector<int>(2));
    for(int i=0; i<2; i++) mul[i][i] = 1;

    mat ba(2, vector<int>(2));
    ba = {{1, 1}, {1, 0}};

    while(N > 0) {
        if(N % 2 == 1) mul = f(mul, ba);

        ba = f(ba, ba);
        N /= 2;
    }

    cout << mul[0][1] << "\n";
}
