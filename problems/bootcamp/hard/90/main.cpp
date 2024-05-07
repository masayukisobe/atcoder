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

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N;
  cin >> N;
  vector<vector<pair<int,ll>>> e(N);
  rep(i,N-1) {
    int u,v;
    ll w;
    cin >> u >> v >> w;
    u--,v--;
    e[u].emplace_back(v,w);
    e[v].emplace_back(u,w);
  }
  vll D(N);
  auto dfs = [&](auto& self, ll d, int i, int pre) -> void {
    D[i] = d;
    for (auto [j,w] : e[i]) {
      if (j!=pre) self(self,d+w,j,i);
    }
  };
  dfs(dfs,0,0,-1);
  rep(i,N) cout << D[i]%2 << endl;
  return 0;
}

