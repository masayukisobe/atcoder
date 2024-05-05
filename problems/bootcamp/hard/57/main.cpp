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
  vector<ll> dp(N+1);
  for (int i=1; i<=N; i++) {
    ll a; cin >> a;
    dp[i] = dp[i-1]+a;
  }
  sort(dp.begin(),dp.end());
  ll ans = 0;
  ll n=1;
  for (int i=1; i<=N; i++) {
    if (dp[i]==dp[i-1]) {
      n++;
    } else {
      if (n>=2) ans += n*(n-1)/2;
      n = 1;
    }
  }
  if (n>=2) ans += n*(n-1)/2;
  cout << ans << endl;
  return 0;
}

