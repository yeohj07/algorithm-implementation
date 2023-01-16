#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    string a, b; cin >> a >> b;

    int cnt = 0;

    for(int i=0; i<a.length(); i++)
        if(a.find(b, i) == i) cnt++;

    cout << cnt << "\n";
}
