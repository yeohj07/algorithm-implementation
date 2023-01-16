#include <bits/stdc++.h>
#define int long long
using namespace std;

struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return (double)a.second/a.first < (double)b.second/b.first;
    }
};

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M, K; cin >> N >> M >> K;

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

    while(K--) {
        int a, b; cin >> a >> b;

        pq.push({a, b});
    }

    while(!pq.empty()) {
        cout << pq.top().first << " " << pq.top().second << "\n";

        pq.pop();
    }
}
