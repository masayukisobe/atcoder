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
  
  ll N;
  cin >> N;
  
  vector<ll> A(N);
  for (int i=0; i<N; i++) {
    ll a; cin >> a; a-=i+1;
    A[i] = a;
  }
  sort(A.begin(),A.end());
  
  vector<ll> dp(N);
  for (int i=0; i<N; i++) {
    dp[i] = A[i];
    if (i>0) dp[i] += dp[i-1];
  }
  
  ll ans = (1LL<<60);
  for (int i=0; i<N; i++) {
    ll gt = dp[N-1]-dp[i] - A[i]*(N-1-i);
    ll le = A[i]*(i+1) - dp[i];
    //debug(gt); debug(le);
    ans = min(gt+le,ans);
  }
  cout << ans << endl;
  return 0;
}

