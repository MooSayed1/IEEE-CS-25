// ﷽
// Contest: Codeforces Round 112 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/165/problem/B
// Memory Limit: 256
// Time Limit: 2000
// Start: Thu Dec  5 21:19:10 2024
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

int n,k;
bool can(int val){
  int ans=0,tmp=1;
  int i=0;
  while(ans<n&&tmp!=0){
    tmp=val/pow(k,i);
    debug(pow(k,i));
    ans+=tmp;
    i++;
  }
  debug(ans);
  return ans>=n;
}
void solve() {
  cin >> n >> k;
  int l=0,r=1e9;
  while(l<=r){
    int mid=(l+r)/2;
    if(can(mid)){
      r=mid-1;
    }else l=mid+1;
  }
  cout<<l<<endl;
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
