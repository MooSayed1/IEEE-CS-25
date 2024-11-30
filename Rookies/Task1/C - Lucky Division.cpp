// ﷽
// Contest: Get Ready
// Judge: Virtual Judge
// URL: https://vjudge.net/contest/676467#problem/C
// Memory Limit: 256
// Time Limit: 2000
// Start: Sat 30 Nov 2024 02:16:35 PM EET
//
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
namespace __gnu_pbds{
    typedef tree<long long,
            null_type,
            less<long long>,
    rb_tree_tag,
    tree_order_statistics_node_update> ordered_set; 
}
using namespace __gnu_pbds;
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

void solve() {
  int n;cin>>n;
  vi arr={4,7,44,47,74,77,444,447,474,477};
  arr.push_back(4);
  arr.push_back(7);
  arr.push_back(47);
  arr.push_back(74);
  arr.push_back(447);
  arr.push_back(474);
  arr.push_back(477);
  for(auto&it:arr){
    if(n%it==0){
      yes;return;
    }
  }
  no;
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
