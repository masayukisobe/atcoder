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
    int a,b; cin >> a >> b; a--, b--;
    e[a].emplace_back(b,i);
    e[b].emplace_back(a,i);
  }
  vi col(N-1);
  auto dfs = [&](auto& self, int c, int i, int pre) -> void {
    int c1 = 1;
    for (auto [j,k] : e[i]) {
      if (j==pre) continue;
      if (c1==c) c1++;
      col[k] = c1;
      self(self, c1, j, i);
      c1++;
    }
  };
  dfs(dfs, 0, 0, -1);
  cout << *max_element(col.begin(), col.end()) << endl;
  rep(i,N-1) cout << col[i] << endl;
  return 0;
}

