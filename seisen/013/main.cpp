// #define _GLIBCXX_DEBUG
// #pragma GCC optimize("O2,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define ii pair<int,int>
#define iii tuple<int,int,int>
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define endl '\n'
#define _(x) #x << "=" << x << " "
#define debug(x) cout << _(x) << endl
#define debug2(x,y) cout << _(x) << _(y) << endl
#define debug3(x,y,z) cout << _(x) << _(y) << _(z) << endl
#define popcount __builtin_popcount
#define INF INT_MAX
#define LL_INF LLONG_MAX
#define rep(a,b) for (int a=0; a<(b); a++)
#define rep2(a,b,c) for (int a=(b); a<(c); a++)
#define rep2e(a,b,c) for (int a=(b); a<=(c); a++)
#define rep2d(a,b,c) for (int a=(b); a>=(c); a--)

//#include <atcoder/all>
//using namespace atcoder;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int R,C;
  cin >> R >> C;
  vi v(C);
  rep(i,R) {
    int bit = 1<<i;
    rep(j,C) {
      int x; cin >> x;
      if (x) v[j] |= bit;
    }
  }
  ll ans = 0;
  for (int mask=0; mask<(1<<R); mask++) {
    ll best = 0;
    rep(j,C) {
      int n = popcount(v[j]^mask);
      best += max(n,R-n);
    }
    ans = max(ans,best);
  }
  cout << ans <<endl;
  return 0;
}

