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
#define debug(x) cout << #x << ": " << x << endl
#define popcount __builtin_popcount
#define INF INT_MAX
#define LL_INF LLONG_MAX
#define ULL_INF ULLONG_MAX
#define rep(a,b) for (int a=0; a<(b); a++)
#define rep2(a,b,c) for (int a=(b); a<(c); a++)
#define rep2e(a,b,c) for (int a=(b); a<=(c); a++)
#define rep2d(a,b,c) for (int a=(b); a>=(c); a--)

//#include <atcoder/all>
//using namespace atcoder;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N; cin >> N;
  vi F(N);
  rep(i,N) rep(j,10) {
    int f; cin >> f;
    if (f) F[i] |= 1<<j;
  }
  vvi P(N,vi(11));
  rep(i,N) rep(j,11) cin >> P[i][j];
  ll ans = -LL_INF;
  rep2(mask,1,1<<10) {
    ll profit = 0;
    rep(i,N) profit += P[i][popcount(mask&F[i])];
    ans = max(ans,profit);
  }
  cout << ans << endl;
  return 0;
}

