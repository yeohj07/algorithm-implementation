#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    vector<int> v(1e6 + 1);

    for(int i=1; i<=1e6; i++)
        for(int j=i; j<=1e6; j+=i) v[j]++;
}
