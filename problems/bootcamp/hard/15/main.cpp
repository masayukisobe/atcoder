// #define _GLIBCXX_DEBUG
// #pragma GCC optimize("O2,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define ii pair<int,int>
#define iii tuple<int,int,int>
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl

//#include <atcoder/all>
//using namespace atcoder;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N;
  cin >> N;
  vector<ll> p(N);
  for (int i=0; i<N; i++) cin >> p[i];
  vector<vector<ll>> dp(N+1,vector<ll>(2));
  dp[0][0]=p[0]+p[1];
  dp[0][1]=-dp[0][0];
  for (int i=1; i<=N-2; i++) {
    int p0 = p[i];
    int p1 = p[i+1];
    dp[i][0]=max(dp[i-1][0]+p1,dp[i-1][1]+p1);
    dp[i][1]=max(dp[i-1][0]-p0-p0+p1,dp[i-1][1]+p0+p0-p1));
  }
  cout << max(dp[N-2][0],dp[N-2][1]) << endl;
  return 0;
}

