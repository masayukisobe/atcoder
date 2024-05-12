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
  
  int N;
  cin >> N;
  vvi dp(N+1,vi(101));
  rep2e(i,1,N) {
    int a; cin >> a;
    if (i>0) {
      rep(j,101) dp[i][j]=dp[i-1][j];
    }
    dp[i][a]++;
  }
  int D;
  cin >> D;
  rep(i,D) {
    int l,r; cin >> l >> r;
    rep2d(j,100,1) {
      int total = dp[N][j];
      int ng = dp[r][j]-dp[l-1][j];
      if (total > ng) {
        cout << j << endl;
        break;
      }
    }
  }
  return 0;
}

