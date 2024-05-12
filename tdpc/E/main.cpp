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
#define rep(a,b) for (int a=0; a<(b); a++)
#define rep2(a,b,c) for (int a=(b); a<(c); a++)
#define rep2e(a,b,c) for (int a=(b); a<=(c); a++)
#define rep2d(a,b,c) for (int a=(b); a>=(c); a--)

#include <atcoder/all>
using namespace atcoder;

using mint = modint1000000007;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int D;
  cin >> D;
  string N;
  cin >> N;
  const int M = N.size();
  vector<vll> dp(M,vll(D));
  dp[0][0] = 1;
  rep(i,M-1) {
    rep(j,D) {
      ll pre = dp[i][j];
      if (pre>0)
        for (int k=0; k<=9; k++)
          dp[i+1][(j+k)%D] += pre;
    }
  }
  rep(i,M) rep(j,D) { debug(i); debug(j); debug(dp[i][j]); }
  mint ans=0;
  int pre=0;
  rep(i,M) {
    int n = N[i]-'0';
    rep(j,D) {
      for (int k=0; k<n; k++) {
        if ((j+k+pre)%D==0) {
          ans += dp[M-1-i][j];
        }
      }
    }
    pre += n;
  }
  cout << ans.val() << endl;
  return 0;
}

