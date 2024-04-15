// #define _GLIBCXX_DEBUG
// #pragma GCC optimize("O2,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define ii pair<int,int>
#define iii tuple<int,int,int>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl

//#include <atcoder/all>
//using namespace atcoder;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N;
  cin >> N;
  vector<vector<int>> e(N,vector<int>());
  for (int i=0; i<N-1; i++) {
    int a,b;
    cin >> a >> b;
    a--,b--;
    e[a].push_back(b);
    e[b].push_back(a);
  }

  vector<int> f(N);
  auto dfs =
    [&N,&e,&f](auto self, int depth, int i) -> ii {
      ii best = {depth,i};
      f[i]=1;
      for (auto j : e[i]) {
        if (f[j]) continue;
        ii ret = self(self,depth+1,j);
        if (ret.first>best.first) best = ret;
      }
      f[i]=0;
      return best;
    };

  auto [d1,k1] = dfs(dfs,0,0);
  auto [d2,k2] = dfs(dfs,0,k1);
  cout << d2+1 << endl;
  return 0;
}

