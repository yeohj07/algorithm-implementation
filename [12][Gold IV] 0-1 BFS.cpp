#include <bits/stdc++.h>
#define int long long
using namespace std;

struct s { int x, y; };

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M; cin >> M >> N;

    vector<vector<char>> v(N, vector<char>(M));

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++) cin >> v[i][j];

    deque<s> d;
    d.push_back({0, 0});

    vector<vector<int>> dis(N, vector<int>(M, INT_MAX));
    dis[0][0] = 0;

    while(!d.empty()) {
        int x = d.front().x, y = d.front().y;
        d.pop_front();

        if(x == N-1 && y == M-1) {
            cout << dis[x][y] << "\n";
            break;
        }

        int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

        for(int i=0; i<4; i++) {
            int nx = x + dx[i], ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(dis[nx][ny] != INT_MAX) continue;

            if(v[nx][ny] == '0') {
                d.push_front({nx, ny});
                dis[nx][ny] = dis[x][y];
            }
            else {
                d.push_back({nx, ny});
                dis[nx][ny] = dis[x][y] + 1;
            }
        }
    }
}
