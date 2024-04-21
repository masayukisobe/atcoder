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
  {
    dp1[0].push_back(0);
    for (int i=0; i<M; i++) {
      for (int k=K; k>=1; k--) {
        for (auto p : dp1[k-1]) {
          if (p+a[i]<=P) {
            dp1[k].push_back(p+a[i]);
          }
        }
      }
    }
    for (auto& v:dp1) sort(v.begin(),v.end());
    //for (int i=0; i<dp1.size(); i++) for (auto b1 : dp1[i]) debug(b1);
  }
  vvll dp2(K+1);
  {
    dp2[0].push_back(0);
    for (int i=M; i<N; i++) {
      for (int k=K; k>=1; k--) {
        for (auto p : dp2[k-1]) {
          if (p+a[i]<=P) {
            dp2[k].push_back(p+a[i]);
          }
        }
      }
    }
    for (auto& v:dp2) sort(v.begin(),v.end());
    //for (int i=0; i<dp2.size(); i++) for (auto b2 : dp2[i]) debug(b2);
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

