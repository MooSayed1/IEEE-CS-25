// سم الله الرحمن الرحيم
// Contest: BFS: Breadth First Search
// Judge: Virtual Judge
// URL: https://vjudge.net/contest/667555#problem/E
// Memory Limit: 512
// Time Limit: 1000
// Start: Wed Dec 11 21:24:01 2024

#include <bits/stdc++.h>
using namespace std;

#ifdef MOHAMED
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif
#define fastio()                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);

#define int long long
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define f(i, a, b) for (int i = a; i < b; i++)
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define vll vector<ll>
#define vi vector<int>
#define pii pair<int,int>
#define OO 2e9
#define endl "\n"
#define popCnt(x) (__builtin_popcountll(x))
const int dx[]{0, 1, 0, -1};
const int dy[]{1, 0, -1, 0};
const char dir[]{'R', 'D', 'L', 'U'};

struct Point {
    int x, y, dist;
    vector<char> path;
};

struct Monster {
    int x, y, dist;
};

template <typename T> istream &operator>>(istream &input, vector<T> &data) {
    for (T &x : data)
        input >> x;
    return input;
}
template <typename T>
ostream &operator<<(ostream &output, const vector<T> &data) {
    for (const T &x : data)
        output << x << " ";
    return output;
}

bool isValid(int x, int y, int n, int m, vector<vector<char>>& grid, vector<vector<int>>& visited, int dist) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#' && visited[x][y] > dist;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<int>> monsterDist(n, vector<int>(m, OO));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    Point start;
    queue<Monster> mq;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                start = {i, j, 0, {}};
            } else if (grid[i][j] == 'M') {
                mq.push({i, j, 0});
                monsterDist[i][j] = 0;
            }
        }
    }

    while (!mq.empty()) {
        Monster curr = mq.front();
        mq.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#' && monsterDist[nx][ny] > curr.dist + 1) {
                monsterDist[nx][ny] = curr.dist + 1;
                mq.push({nx, ny, curr.dist + 1});
            }
        }
    }

    queue<Point> pq;
    pq.push(start);
    visited[start.x][start.y] = true;

    while (!pq.empty()) {
        Point curr = pq.front();
        pq.pop();

        if (curr.x == 0 || curr.x == n - 1 || curr.y == 0 || curr.y == m - 1) {
            yes;
            cout << curr.dist << "\n";
            for (char c : curr.path) cout << c;
            cout << "\n";
            return;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if (isValid(nx, ny, n, m, grid, monsterDist, curr.dist + 1)) {
                monsterDist[nx][ny] = curr.dist + 1;
                vector<char> newPath = curr.path;
                newPath.push_back(dir[i]);
                pq.push({nx, ny, curr.dist + 1, newPath});
            }
        }
    }

    no;
}

int32_t main() {
    fastio();
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
