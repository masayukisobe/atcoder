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
  
  ll L,R;
  cin >> L >> R;
  vll x(2019*2019);
  rep(i,2019) {
    rep(j,2019) {
      x[i*2019+j] = i*j%2019;
    }
  }
  ll l = L%2019;
  ll r = R%2019;
  if (R-L<2019 and l<r) {
    ll ans = 2019;
    rep2e(i,l,r) {
      rep2e(j,i+1,r) {
        ans = min(ans,x[i*2019+j]);
      }
    }
    assert(ans<2019);
    cout << ans << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}

