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
const int dx[]{0, 1, 0, -1, -1, -1, 1, 1};
const int dy[]{1, 0, -1, 0, -1, 1, -1, 1};
 
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
 
int n,m;
vector<vector<bool>>visited;
void dfs(int i,int j){
  if(i<0||i>=n||j<0||j>=m||visited[i][j])return;
  visited[i][j]=1;
  for(int k=0;k<4;++k)
    dfs(i+dx[k],j+dy[k]);
}
 
void solve() {
  cin>>n>>m;
  vector<vector<char>>arr(n,vector<char>(m));
  visited.assign(n,vector<bool>(m,false));
 
  for(int i=0;i<n;++i){
    for(int j=0;j<m;++j){
      cin>>arr[i][j];
      if(arr[i][j]=='#')
      {
        visited[i][j]=1;
      }
    }
  }
 
  int cnt = 0;
  for(int i=0;i<n;++i){
    for(int j=0;j<m;++j){
      if(visited[i][j])
        continue;
      dfs(i,j);
      cnt++;
    }
  }
  cout << cnt << endl;
}
int32_t main() {
 
  //  freopen("whereami.in", "r", stdin);
  //  freopen("whereami.out", "w", stdout);
  fastio();
  int t = 1;
  // cin>>t;
  while (t--)
    solve();
  return 0;
}
