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
const int knight_dx[]{2, 2, -2, -2, 1, 1, -1, -1};
const int knight_dy[]{1, -1, 1, -1, 2, -2, 2, -2};

struct Cell {
    int x, y, dist;
};

bool isValid(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

int bfsKnight(pair<int, int> start, pair<int, int> end) {
    vector<vector<bool>> visited(8, vector<bool>(8, false));
    queue<Cell> q;
    q.push({start.first, start.second, 0});
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        Cell curr = q.front();
        q.pop();

        if (curr.x == end.first && curr.y == end.second)
            return curr.dist;

        for (int i = 0; i < 8; ++i) {
            int nx = curr.x + knight_dx[i];
            int ny = curr.y + knight_dy[i];

            if (isValid(nx, ny) && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny, curr.dist + 1});
            }
        }
    }

    return -1; 
}

pair<int, int> parsePosition(const string& pos) {
    return {pos[0] - 'a', pos[1] - '1'};
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        string start, end;
        cin >> start >> end;
        pair<int, int> startPos = parsePosition(start);
        pair<int, int> endPos = parsePosition(end);

        cout << bfsKnight(startPos, endPos) << "\n";
    }
}

int32_t main() {
    fastio();
    int t = 1;
    while (t--)
        solve();
    return 0;
}
