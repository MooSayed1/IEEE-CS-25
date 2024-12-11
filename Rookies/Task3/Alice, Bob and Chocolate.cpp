// ﷽
// Contest: CodeForces
// Judge: Virtual Judge
// URL: https://vjudge.net/problem/CodeForces-6C
// Memory Limit: 64
// Time Limit: 2000
// Start: Wed Dec 11 21:07:53 2024
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

void solve()
{
  int a,b,x=0,y=0;
  cin>>a;
  vector<int>v;
  int u=5;
  for(int i=0;i<a;i++)
  {
    cin>>b;
    v.push_back(b);
  }
  int l=0,r=a-1;
  int sum1=0,sum2=0;
  while(l<=r)
  {
    if((sum1+v[l])<(sum2+v[r]))
    {
      x++;
      sum1+=v[l];
      l++;
    }
    else if(((sum1+v[l])>(sum2+v[r])))
    {
      y++;
      sum2+=v[r];
      r--;
    }
    else
  {
      x++;
      sum1+=v[l];
      l++;

    }
  }
  cout<<x<<" "<<y<<endl;
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
