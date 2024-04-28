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
  
  int N,Q;
  cin >> N >> Q;
  vector<vector<int>> e(N+1);
  for (int i=0; i<N-1; i++) {
    int a,b; cin >> a >> b;
    e[a].push_back(b);
    e[b].push_back(a);
  }
  vector<int> c(N+1);
  for (int i=0; i<Q; i++) {
    int p,x; cin >> p >> x;
    c[p] += x;
  }
  vector<ll> ans(N+1);
  auto dfs =
    [&](auto& self, int i, int pre) -> void {
      ans[i] = ans[pre]+c[i];
      for (int j : e[i]) {
        if (j==pre) continue;
        self(self,j,i);
      }
    };
  dfs(dfs,1,0);
  for (int i=1; i<=N; i++) {
    if (i>1) cout << " ";
    cout << ans[i];
  }
  cout << endl;
  return 0;
}

