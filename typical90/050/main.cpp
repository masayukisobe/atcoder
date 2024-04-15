// #define _GLIBCXX_DEBUG
// #pragma GCC optimize("O2,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define ii pair<int,int>
#define iii tuple<int,int,int>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl

#define lb lower_bound
#define ub upper_bound

template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return true; } else return false; }

//#include <atcoder/all>
//using namespace atcoder;

const int MOD = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  ll N,L;
  cin >> N >> L;
  vector<ll> dp(N+1);
  dp[0] = 1;
  for (ll i=1; i<=N; i++) {
    dp[i] = dp[i-1];
    if (i-L>=0) dp[i] = (dp[i]+dp[i-L])%MOD;
  }
  cout << dp[N] << endl;
  return 0;
}

