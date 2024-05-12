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

//#include <atcoder/all>
//using namespace atcoder;

double solve(ll N,ll D) {
  int a2=0, a3=0, a5=0;
  ll d=D;
  while (d%2==0) { d/=2; a2++; }
  while (d%3==0) { d/=3; a3++; }
  while (d%5==0) { d/=5; a5++; }
  if (d>1) return 0;

  auto index = [&](int i, int j, int k) -> int {
    if (i>a2) i=a2;
    if (j>a3) j=a3;
    if (k>a5) k=a5;
    return i*(a3+1)*(a5+1)+j*(a5+1)+k;
  };
  vector<iii> dice={{0,0,0},{1,0,0},{0,1,0},{2,0,0},{0,0,1},{1,1,0}};
  vector<vector<double>> dp(N+1,vector<double>((a2+1)*(a3+1)*(a5+1)));
  dp[0][0] = 1.0;
  rep(n,N) {
    rep2e(i,0,a2) {
      rep2e(j,0,a3) {
        rep2e(k,0,a5) {
          double p = dp[n][index(i,j,k)]/6.0;
          for (auto [x,y,z]:dice) {
            dp[n+1][index(i+x,j+y,k+z)] += p;
          }
        }
      }
    }
  }
  return dp[N][index(a2,a3,a5)];
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  ll N,D;
  cin >> N >> D;
  cout << fixed << setprecision(10);
  cout << solve(N,D) << endl;
  return 0;
}

