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
  
  int N,K;
  cin >> N >> K;
  // nCm = C[n][m]
  vector<vector<mint>> C(N+1,vector<mint>(N+1));
  C[0][0] = 1;
  rep2e(i,1,N) {
    rep2e(j,0,i) {
      C[i][j] = C[i-1][j] + (j>0 ? C[i-1][j-1] : 0);
      //if (C[i][j].val()>0) { debug(i); debug(j); debug(C[i][j].val()); }
    }
  }
  rep2e(i,1,K) {
    mint ans = C[N-K+1][i]*C[K-1][i-1];
    cout << ans.val() << endl;
  }
  
  return 0;
}

