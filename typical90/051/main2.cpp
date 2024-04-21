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

using vvll = vector<vector<ll>>;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N,K;
  cin >> N >> K;
  ll P;
  cin >> P;
  vector<ll> a(N);
  for (int i=0; i<N; i++) {
    cin >> a[i];
  }
  int M = N/2;

  vvll dp1(K+1);
  vvll dp2(K+1);
  vector<tuple<int,int,vvll&>> dps;
  dps.emplace_back(0,M,dp1);
  dps.emplace_back(M,N,dp2);
  for (auto [n1,n2,dp] : dps) {
    for (ll i=0; i<(1<<(n2-n1)); i++) {
      int k=0, p=0;
      ll mask = i;
      for (int j=0; mask>0 && p<=P; mask>>=1,j++) {
        if (mask&1) p+=a[n1+j],k++;
      }
      if (p<=P) dp[k].push_back(p);
    }
    for (auto& v:dp) sort(v.begin(),v.end());
  }

  ll ans = 0;
  for (int k=0; k<=K; k++) {
    for (auto p: dp1[k]) {
      auto& peers = dp2[K-k];
      auto it = lower_bound(peers.begin(),peers.end(),P-p+1);
      ans += (ll)(it-peers.begin());
    }
  }
  
  cout << ans << endl;
  return 0;
}

