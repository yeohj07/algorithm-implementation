#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int Max = 1e8 + 1;
    vector<bool> p(Max);

    vector<int> v;
    v.push_back(2);

    for(int i=3; i<Max; i+=2) {
        if(p[i]) continue;

        v.push_back(i);

        for(int j=i; j<Max; j+=i*2) p[j] = true;
    }
}
