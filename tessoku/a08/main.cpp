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
  
  int H,W;
  cin >> H >> W;
  const int H2 = H+2;
  const int W2 = W+2;
  vll dp(H2*W2);
  rep2e(i,1,H) {
    rep2e(j,1,W) {
      ll x; cin >> x;
      int k = i*W2+j;
      dp[k] = x+dp[k-W2]+dp[k-1]-dp[k-W2-1];
    }
  }
  int Q;
  cin >> Q;
  rep(i,Q) {
    int a,b,c,d; cin >> a >> b >> c >> d;
    ll ans = dp[c*W2+d];
    ans -= dp[(a-1)*W2+d];
    ans -= dp[c*W2+(b-1)];
    ans += dp[(a-1)*W2+(b-1)];
    cout << ans << endl;
  }
  return 0;
}

