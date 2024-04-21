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

  vector<vector<ll>> e(N);
  for (ll i=0; i<N-1; i++) {
    ll a,b;
    cin >> a >> b;
    a--, b--;
    e[a].push_back(b);
    e[b].push_back(a);
  }

  vector<ll> dp(N);
  auto dfs =
    [&N,&e,&dp](auto self, ll pos, ll pre) -> void {
      dp[pos]=1;
      for (auto i: e[pos]) {
        if (i!=pre) {
          self(self,i,pos);
          dp[pos] += dp[i];
        }
      }
    };
  dfs(dfs,0,-1);
  ll ans = 0;
  for (ll i=0; i<N; i++) {
    for (ll j : e[i]) if (i<j) {
        ll n1 = min(dp[i],dp[j]);
        ll n2 = N-n1;
        ans += n1*n2;
    }
  }
  cout << ans << endl;
  return 0;
}

