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
  vector<vector<ii>> e(N);
  rep(i,N-1) {
    int a,b; 
    ll c;
    cin >> a >> b >> c;
    a--,b--;
    e[a].emplace_back(b,c);
    e[b].emplace_back(a,c);
  }

  vll depth(N);
  vll dist(N);
  
  // calc min(M) s.t. 2^M >= N
  int M = 1; while ((1<<M)<N) M++; 

  vvi parent(N,vi(M));
  auto dfs = [&](auto& self, int de, ll di, int i, int p) -> void {
    parent[i][0] = p;
    depth[i] = de;
    dist[i] = di;
    for (auto [j,c] : e[i]) {
      if (j==p) continue;
      self(self, de+1, di+c, j, i);
    }
  };
  dfs(dfs, 0, 0, 0, -1);
  rep2(m,1,M) {
    rep(n,N) {
      int ances = parent[n][m-1];
      if (ances<0)
        parent[n][m] = -1;
      else
        parent[n][m] = parent[ances][m-1];
    }
  }
  auto lca = [&](int i, int j) -> int {
    // ensure i is deeper
    if (depth[i]<depth[j]) {
      swap(i,j);
    }
    rep(m,M) {
      int diff = depth[i]-depth[j];
      if (diff>>m & 1) {
        i = parent[i][m];
      }
    }
    assert(depth[i]==depth[j]);
    
    if (i==j) return i;
    rep2d(m,M-1,0) {
      if (parent[i][m]!=parent[j][m]) {
        i = parent[i][m];
        j = parent[j][m];
      }
    }
    return parent[i][0];
  };
  
  int Q,K;
  cin >> Q >> K;
  K--;
  rep(i,Q) {
    int x,y;
    cin >> x >> y;
    x--,y--;
    ll d1 = dist[x]+dist[K]-2*dist[lca(x,K)];
    ll d2 = dist[y]+dist[K]-2*dist[lca(y,K)];
    //debug(x); debug(y); debug(d1); debug(d2);
    cout << d1+d2 << endl;
  }
  return 0;
}

