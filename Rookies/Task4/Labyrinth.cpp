// ﷽
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1192/
// Memory Limit: 512
// Time Limit: 1000
// Start: Wed 03 Jul 2024 09:41:08 PM EEST
//
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
 
#define ll long long
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define vll vector<ll>
#define vi vector<int>
#define pii pair<int,int>
#define OO 2e9
#define endl "\n"
const int dx[]{1, 0, -1, 0};
const int dy[]{0, 1, 0, -1};
const char dir[] = {'D', 'R', 'U', 'L'};
 
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
// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z
 
struct Point {
    int x, y;
    int dist;
    vector<char> path;
};
 
bool isValid(int x, int y, int n, int m, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#' && !visited[x][y];
}
 
void solve() {
    int n, m;
    cin >> n >> m;
 
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
 
    Point start, end;
 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                start = {i, j, 0, {}};
            }
            if (grid[i][j] == 'B') {
                end = {i, j, 0, {}};
            }
        }
    }
 
    queue<Point> q;
    q.push(start);
    visited[start.x][start.y] = true;
 
    while (!q.empty()) {
        Point curr = q.front();
        q.pop();
 
        if (curr.x == end.x && curr.y == end.y) {
            yes;
            cout << curr.dist << "\n";
            for (char c : curr.path) cout << c;
            cout << "\n";
            return;
        }
 
        for (int i = 0; i < 4; ++i) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];
 
            if (isValid(nx, ny, n, m, grid, visited)) {
                visited[nx][ny] = true;
                vector<char> newPath = curr.path;
                newPath.push_back(dir[i]);
                q.push({nx, ny, curr.dist + 1, newPath});
            }
        }
    }
 
    no;
}
 
int32_t main() {
    fastio();
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
