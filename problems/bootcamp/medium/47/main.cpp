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
  
  int N,P;
  cin >> N >> P;
  vector<vll> dp(2,vll(2));
  dp[0][0]=1;
  rep(i,N) {
    auto &dp0=dp[i%2];
    auto &dp1=dp[(i+1)%2];
    int a; cin >> a;
    // not eat
    dp1[0] = dp0[0];
    dp1[1] = dp0[1];
    // eat
    dp1[a%2] += dp0[0];
    dp1[(a+1)%2] += dp0[1];
  }
  cout << dp[N%2][P] << endl;
  return 0;
}

