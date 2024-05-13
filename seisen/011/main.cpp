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
  
  int N,M;
  cin >> N >> M;
  vvi s(M);
  rep(i,M) {
    int k; cin >> k;
    s[i].reserve(k);
    rep(j,k) {
      int x; cin >> x; x--;
      s[i].push_back(x);
    }
  }
  vi p(M);
  rep(i,M) cin >> p[i];

  int ans=0;
  for (int mask=0; mask<(1<<N); mask++) {
    bool ok=true;
    rep(i,M) {
      int n=0;
      for (int x : s[i]) if (mask&(1<<x)) n^=1;
      if (n!=p[i]) {
        ok=false; break;
      }
    }
    if (ok) ans++;
  }
  cout << ans << endl;
  return 0;
}

