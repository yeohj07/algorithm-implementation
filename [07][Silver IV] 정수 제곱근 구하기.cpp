#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;

    int l = 0, r = LLONG_MAX;
    while(l <= r) {
        int m = (l + r)/2;

        unsigned long long mm = m * m;

        if(mm >= N) r = m - 1;
        else l = m + 1;
    }

    cout << l << "\n";
}
