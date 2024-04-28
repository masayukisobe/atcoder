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
  
  int N,K;
  cin >> N >> K;
  vector<ll> x(N);
  for (int i=0; i<N; i++) {
    cin >> x[i];
  }
  vector<ll> dp(N);
  for (int i=1; i<N; i++) {
    dp[i] = dp[i-1]+x[i]-x[i-1];
  }
  ll ans = (1LL<<60);
  for (int i=0; i+K-1<N; i++) {
    ll t = dp[i+K-1]-dp[i];
    //debug(i);debug(t);
    t += min(abs(x[i]),abs(x[i+K-1]));
    //debug(t);
    ans = min(t,ans);
  }  
  cout << ans << endl;
  return 0;
}

