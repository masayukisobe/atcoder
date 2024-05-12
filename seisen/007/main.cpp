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

ll scale(ll dx,ll dy) {
  ll x=abs(dx);
  ll y=abs(dy);
  ll l=x+y;
  ll ret = l*l-2*x*y;
  //debug3(dx,dy,ret);
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N;
  cin >> N;
  vector<ii> v;
  v.reserve(N);
  unordered_set<int> us;
  rep(i,N) {
    ll x,y; cin >> x >> y;
    v.emplace_back(x,y);
    us.emplace(x<<16|y);
  }
  ll ans=0;
  rep(i,N-1) {
    auto [x1,y1] = v[i];
    rep2(j,i+1,N) {
      auto [x2,y2] = v[j];
      int dx = x2-x1;
      int dy = y2-y1;
      int x3 = x2+dy;
      int y3 = y2-dx;
      if (x3<0 or y3<0) continue;
      int x4 = x3-dx;
      int y4 = y3-dy;
      if (x4<0 or y4<0) continue;
      if (!us.contains(x3<<16|y3)) continue;
      if (!us.contains(x4<<16|y4)) continue;
      ans = max(ans,scale(dx,dy));
    }
  }
  cout << ans << endl;
  return 0;
}

